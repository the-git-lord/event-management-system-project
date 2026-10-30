#include "../headers/Waitlist.h"
#include <queue>

Waitlist::Waitlist() {
    waitlistCapacity = 10;
}

bool Waitlist::addParticipant(const std::string& name) {
    if (participants.size() >= waitlistCapacity) {
        return false;
    }

    participants.push(name);
    return true;
}

bool Waitlist::removeParticipant(const std::string& name) {
    std::queue<std::string> temp;
    bool removed = false;

    while (!participants.empty()) {
        std::string current = participants.front();
        participants.pop();

        if (current == name && !removed) {
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

std::string Waitlist::getNextParticipant() const {
    if (participants.empty()) {
        return "";
    }

    return participants.front();
}

int Waitlist::getSize() const {
    return participants.size();
}