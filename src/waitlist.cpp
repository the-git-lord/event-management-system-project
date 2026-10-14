#include "../headers/Waitlist.h"
#include <iostream>

void Waitlist::addParticipant(const std::string& name) {
    participants.push_back(name);
}

void Waitlist::viewParticipants() const {
    if (participants.empty()) {
        std::cout << "The waitlist is empty." << std::endl;
        return;
    }

    for (int i = 0; i < participants.size(); i++) {
        std::cout << i + 1 << ". " << participants[i] << std::endl;
    }
}

bool Waitlist::removeParticipant(const std::string& name) {
    for (int i = 0; i < participants.size(); i++) {
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