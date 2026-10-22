#include "admin.hpp"

Administrator::Administrator(std::string name, std::string username, std::string password)
    : User(name, username, password, Role::ADMINISTRATOR) {}

bool Administrator::createEvent(std::vector<Event>& events, Event event) {
    if (!hasAdminPrivileges()) 
        return false;
    

    if (event.getName().empty()) 
        return false;

    if (findEvent(events, event.getName()) != nullptr) 
        return false;

    events.push_back(event);
    return true;
}

bool Administrator::deleteEvent(std::vector<Event>& events, std::string eventName) {
    if (!hasAdminPrivileges()) 
        return false;
    
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getName() == eventName) {
            // TODO: notify registered and waitlisted participants
            events.erase(it);
            return true;
        }
    }

    return false;
}

bool Administrator::updateEventCapacity(std::vector<Event>& events, std::string eventName, int capacity) {
    if (!hasAdminPrivileges()) 
        return false;

    if (capacity <= 0) 
        return false;
    
    Event* event = findEvent(events, eventName);
    if (event == nullptr) 
        return false;

    // TODO: reject if capacity drops below current registrations,
    // and move people off the waitlist if capacity increases.
    event->setCapacity(capacity);
    return true;
}

Event* Administrator::findEvent(std::vector<Event>& events, std::string eventName) {
    for (Event& event : events) {
        if (event.getName() == eventName) {
            return &event;
        }
    }
    return nullptr;
}
