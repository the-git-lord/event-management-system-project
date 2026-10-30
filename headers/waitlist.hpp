#include <iostream>
#include <string>
#include <queue>

#include "user.hpp"

class Waitlist {
private:
    std::queue<User> participants;
    int waitlistCapacity;

public:
    Waitlist();

    bool addParticipant(const User name);
    bool removeParticipant(const User name);
    bool hasParticipants() const;
    User getNextParticipant() const;
    int getSize() const;
};