#include "user.hpp"

// Constructor for the User class
User::User(std::string name) {
    this->name = name;
}

// Returns the user's name
std::string User::getName() const {
    return name;
}

// Constructor for the Participant class
Participant::Participant(std::string name)
    : User(name) {
}

// Constructor for the Administrator class
Administrator::Administrator(std::string name)
    : User(name) {
} 