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

void Waitlist::viewParticipants() const {
    if (participants.empty()) {
        std::cout << "The waitlist is empty." << std::endl;
        return;
    }

    for (std::size_t i = 0; i < participants.size(); i++) {
        std::cout << i + 1 << ". "
                  << participants[i].getName() << std::endl;
    }
}

bool Waitlist::removeParticipant(const User name) {
    for (std::size_t i = 0; i < participants.size(); i++) {
        if (participants[i].getName() == name.getName()) {
            participants.erase(participants.begin() + i);
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

    return participants[0];
}

int Waitlist::getSize() const {
    return participants.size();
}