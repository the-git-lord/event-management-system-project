#include <iostream>
#include <string>
#include "event.hpp"

int main() {
    Event event;

    // Create an event
    event.setName("CS410 Workshop");
    event.setCapacity(2);

    std::string name;

    // Ask the participant to enter their name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Try to register the participant
    if (event.registerParticipant(name)) {
        std::cout << "You have successfully signed up!"
                  << std::endl;
    } else {
        std::cout << "Signup failed."
                  << std::endl;
    }

    return 0;
}
