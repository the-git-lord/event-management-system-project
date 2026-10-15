#include "user.hpp"

User::User(std::string name) {
    this->name = name;
}

std::string User::getName() const {
    return name;
}

Participant::Participant(std::string name)
    : User(name) {
}

Administrator::Administrator(std::string name)
    : User(name) {
}
