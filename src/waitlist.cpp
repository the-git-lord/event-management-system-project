#include <iostream>
#include "waitlist.hpp"

Waitlist::Waitlist() {}

void Waitlist::addParticipant(const User name) {
    participants.push_back(name);
}

void Waitlist::viewParticipants() const {
    if (participants.empty()) {
        std::cout << "The waitlist is empty." << std::endl;
        return;
    }

    for (std::size_t i = 0; i < participants.size(); i++) {
        std::cout << i + 1 << ". " << participants[i] << std::endl;
    }
}

bool Waitlist::removeParticipant(const User name) {
    for (std::size_t i = 0; i < participants.size(); i++) {
        if (participants[i] == name) {
            participants.erase(participants.begin() + i);
            return true;
        }
    }

    return false;
}

bool Waitlist::hasParticipants() const {
    return !participants.empty();
}

std::string Waitlist::getNextParticipant() const {
    if (participants.empty()) {
        return "";
    }

    return participants[0];
}

int Waitlist::getSize() const {
    return participants.size();
}
