#include <iostream>
#include "waitlist.hpp"

Waitlist::Waitlist() {
    waitlistCapacity = 10;
}

bool Waitlist::addParticipant(const User name) {
    if (participants.size() >= waitlistCapacity) {
        return false;
    }

    participants.push_back(name);
    return true;
}

bool Waitlist::removeParticipant(const User name) {
    for (auto it = participants.begin(); it != participants.end(); it++) {
        if (it->getName() == name.getName()) {
            participants.erase(it);
            return true;
        }
    }

    return false;
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