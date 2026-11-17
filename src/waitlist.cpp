#include <iostream>
#include "waitlist.hpp"

Waitlist::Waitlist() {
    waitlistCapacity = 10;
}

bool Waitlist::addParticipant(const User name) {
    if (getSize() >= waitlistCapacity) {
        return false;
    }

    participants.push_back(name);
    return true;
}

bool Waitlist::addPriorityParticipant(const User name) {
    if (getSize() >= waitlistCapacity) {
        return false;
    }

    priorityParticipants.push_back(name);
    return true;
}

bool Waitlist::removeParticipant(const User name) {
    for (std::list<User>::iterator it = priorityParticipants.begin();
         it != priorityParticipants.end(); it++) {

        if (it->getName() == name.getName()) {
            priorityParticipants.erase(it);
            return true;
        }
    }

    for (std::list<User>::iterator it = participants.begin();
         it != participants.end(); it++) {

        if (it->getName() == name.getName()) {
            participants.erase(it);
            return true;
        }
    }

    return false;
}

bool Waitlist::hasParticipants() const {
    return !priorityParticipants.empty() || !participants.empty();
}

User Waitlist::getNextParticipant() const {
    if (!priorityParticipants.empty()) {
        return priorityParticipants.front();
    }

    if (!participants.empty()) {
        return participants.front();
    }

    Participant blank = Participant(" ", " ", " ");
    return blank;
}

int Waitlist::getSize() const {
    return participants.size() + priorityParticipants.size();
}