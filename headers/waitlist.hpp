#include <iostream>
#include <string>
#include <list>

#include "user.hpp"

class Waitlist {
private:
    std::list<User> participants;
    std::list<User> priorityParticipants;
    int waitlistCapacity;

public:
    Waitlist();

    bool addParticipant(const User name);
    bool addPriorityParticipant(const User name);
    bool removeParticipant(const User name);
    bool hasParticipants() const;
    User getNextParticipant() const;
    int getSize() const;
};