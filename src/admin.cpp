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

bool Administrator::warnUser(User& user) {
    if (!hasAdminPrivileges()) 
        return false;

    user.warnings++;
    return true;
}

bool Administrator::removeUserFromEvent(Event& event, User& user) {
    if (!hasAdminPrivileges())
        return false;
    
    return event.removeEnrolledParticipant(user.getUsername());
}

bool Administrator::banUser(User& user) {
    if (!hasAdminPrivileges())
        return false;
    
    // Admins cannot ban other admins
    if (user.getRole() == Role::ADMINISTRATOR)
        return false;

    user.banned = true;
    return true;
}

bool Administrator::unbanUser(User& user) {
    if (!hasAdminPrivileges())
        return false;
    
    user.banned = false;
    return true;
}

bool Administrator::handleReport(Report& report, User& reportedUser, ReportAction action, Event* event) {
    if (!hasAdminPrivileges())
        return false;
    
    if (!report.isOpen())
        return false;
    
    // Make sure we are acting on the user the report is about
    if (report.getReportedUsername() != reportedUser.getUsername())
        return false;

    bool success = false;

    switch (action) {
        case ReportAction::WARNING:
            success = warnUser(reportedUser);
            break;
        case ReportAction::REMOVED_FROM_EVENT:
            if (event != nullptr)
               success = removeUserFromEvent(*event, reportedUser);
            break;
        case ReportAction::BANNED:
            success = banUser(reportedUser);
            break;
        case ReportAction::NONE:
            break;
    }

    if (success) 
        report.resolve(action);

    return success;
}

bool Administrator::dismissReport(Report& report) {
    if (!hasAdminPrivileges())
        return false;
    
    if (!report.isOpen())
        return false;

    report.dismiss();
    return true;
}
