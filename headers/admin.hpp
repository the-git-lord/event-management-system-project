#ifndef ADMIN
#define ADMIN

#include <string>
#include <vector>

#include "user.hpp"
#include "event.hpp"

class Administrator : public User {
public:
    Administrator(std::string name, std::string username, std::string password);

    // All actions return false if the administrator is not logged in, true otherwise
    bool createEvent(std::vector<Event>& events, Event event);
    bool deleteEvent(std::vector<Event>& events, std::string eventName);
    bool updateEventCapacity(std::vector<Event>& events, std::string eventName, int Capacity);

    Event* findEvent(std::vector<Event>& events, std::string eventName);
};

#endif