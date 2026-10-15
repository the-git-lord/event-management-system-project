#include "user.hpp"
#include "event.hpp"

User::User(std::string name) {
    this->name = name;
}

std::string User::getName() const {
    return name;
}
bool User::registerParticipant(Event& event) {
    if (name.empty()) {
        return false;
    }

    if (event.participants.size() >= event.capacity) {
        return false;
    }

    event.participants.push_back(name);

    return true;
}

Participant::Participant(std::string name)
    : User(name) {
}

Administrator::Administrator(std::string name)
    : User(name) {
}