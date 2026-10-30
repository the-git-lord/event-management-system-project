#ifndef ADMIN
#define ADMIN

#include <string>
#include <vector>

#include "user.hpp"
#include "event.hpp"
#include "report.hpp"

class Administrator : public User {
public:
    Administrator(std::string name, std::string username, std::string password);

    // All actions return false if the administrator is not logged in, true otherwise
    bool createEvent(std::vector<Event>& events, Event event);
    bool deleteEvent(std::vector<Event>& events, std::string eventName);
    bool updateEventCapacity(std::vector<Event>& events, std::string eventName, int Capacity);

    Event* findEvent(std::vector<Event>& events, std::string eventName);

    // Actions on reported users
    bool warnUser(User& user);
    bool removeUserFromEvent(Event& event, User& user);
    bool banUser(User& user);
    bool unbanUser(User& user);

    // Apply an action to the reported user and close the report.
    // event is only needed for REMOVED_FROM_EVENT.
    bool handleReport(Report& report, User& reportedUser, ReportAction action, Event* event = nullptr);
    bool dismissReport(Report& report);
};

#endif