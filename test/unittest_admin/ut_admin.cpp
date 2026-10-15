#include <iostream>
#include <string>
#include <vector>

#include "event.hpp"
#include "user.hpp"
#include "admin.hpp"

int passed = 0;
int failed = 0;

void check(bool condition, std::string testName) {
    if (condition) {
        std::cout << "[PASS] " << testName << std::endl;
        passed++;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
        failed++;
    }
}

Event makeEvent(std::string name, int capacity) {
    Event event = Event();
    event.setName(name);
    event.setCapacity(capacity);
    event.setLocation("ISC", "5300");
    return event;
}

void testLogin() {
    Administrator admin("Raghav", "raghav", "pass123");

    check(!admin.isLoggedIn(), "Admin should not be logged in initially");
    check(!admin.login("raghav", "wrong"), "Admin should not be able to log in with incorrect password");
    check(!admin.login("someone", "pass123"), "Admin should not be able to log in with incorrect username");
    check(admin.login("raghav", "pass123"), "Admin should be able to log in with correct credentials");
    check(admin.isLoggedIn(), "Admin should be logged in after successful login");

    admin.logout();
    check(!admin.isLoggedIn(), "Admin should not be logged in after logout");
}

void testPrivileges() {
    Administrator admin("Raghav", "raghav", "pass123");
    Participant participant("Sam", "sam", "abc");

    check(!admin.hasAdminPrivileges(), "Admin should not have privileges when not logged in");
    admin.login("raghav", "pass123");
    check(admin.hasAdminPrivileges(), "Admin should have privileges when logged in");

    participant.login("sam", "abc");
    check(!participant.hasAdminPrivileges(), "Participant should not have admin privileges");
    check(participant.getRole() == Role::PARTICIPANT, "Participant has PARTICIPANT role");
    check(admin.getRole() == Role::ADMINISTRATOR, "Admin has ADMINISTRATOR role");
}

void testCreateEvent() {
    std::vector<Event> events;
    Administrator admin("Raghav", "raghav", "pass123");

    check(!admin.createEvent(events, makeEvent("Workshop", 30)), "cannot create event when not logged in");
    check(events.size() == 0, "No events should be created when not logged in");

    admin.login("raghav", "pass123");
    check(admin.createEvent(events, makeEvent("Workshop", 30)), "can create event when logged in");
    check(events.size() == 1, "One event should be created when logged in");
    check(!admin.createEvent(events, makeEvent("Workshop", 30)), "cannot create duplicate event");
    check(!admin.createEvent(events, makeEvent("", 10)), "cannot create event with empty name");
    check(events.size() == 1, "Only one event should exist after failed creation attempts");
}

void testDeleteEvent() {
    std::vector<Event> events;
    Administrator admin("Raghav", "raghav", "pass123");
    admin.login("raghav", "pass123");

    admin.createEvent(events, makeEvent("Workshop", 30));
    admin.createEvent(events, makeEvent("Conference", 200));

    check(!admin.deleteEvent(events, "NonExistentEvent"), "cannot delete non-existent event");
    check(events.size() == 2, "No events should be deleted when event does not exist");

    admin.logout();
    check(!admin.deleteEvent(events, "Workshop"), "cannot delete event when not logged in");
    check(events.size() == 2, "No events should be deleted when not logged in");

    admin.login("raghav", "pass123");
    check(admin.deleteEvent(events, "Workshop"), "can delete event when logged in");
    check(events.size() == 1, "One event should be deleted when logged in");
    check(admin.findEvent(events, "Workshop") == nullptr, "Deleted event should not be found");
    check(admin.findEvent(events, "Conference") != nullptr, "Remaining event should be found");
}

void testUpdateCapacity() {
    std::vector<Event> events;
    Administrator admin("Raghav", "raghav", "pass123");
    admin.login("raghav", "pass123");
    admin.createEvent(events, makeEvent("Workshop", 30));

    check(admin.updateEventCapacity(events, "Workshop", 50), "can update capacity of existing event");
    check(admin.findEvent(events, "Workshop")->getCapacity() == 50, "Capacity should be updated correctly");
    check(!admin.updateEventCapacity(events, "Workshop", 0), "cannot update capacity to non-positive value");
    check(!admin.updateEventCapacity(events, "NonExistentEvent", 10), "cannot update capacity of non-existent event");

    admin.logout();
    check(!admin.updateEventCapacity(events, "Workshop", 70), "cannot update capacity when not logged in");
    check(events[0].getCapacity() == 50, "Capacity should remain unchanged when not logged in");
}

int main() {
    testLogin();
    testPrivileges();
    testCreateEvent();
    testDeleteEvent();
    testUpdateCapacity();
    
    std::cout << std::endl << passed << " passed, " << failed << " failed" << std::endl;
    return failed == 0 ? 0 : 1;
}