#include <iostream>
#include "waitlist.hpp"

Waitlist::Waitlist() {
    waitlistCapacity = 10;
}

bool Waitlist::addParticipant(const User name) {
    if (participants.size() >= waitlistCapacity) {
        return false;
    }

    participants.push(name);
    return true;
}

bool Waitlist::removeParticipant(const User name) {
    std::queue<User> temp;
    bool removed = false;

    while (!participants.empty()) {
        User current = participants.front();
        participants.pop();

        if (current.getName() == name.getName() && !removed) {
            removed = true;
        } else {
            temp.push(current);
        }
    }

    participants = temp;
    return removed;
}

bool Waitlist::hasParticipants() const {
    return !participants.empty();
}

User Waitlist::getNextParticipant() const {
    if (participants.empty()) {
        Participant blank = Participant(" ", " ", " ");
        return blank;
    }

    return participants.front();
}

int Waitlist::getSize() const {
    return participants.size();
}