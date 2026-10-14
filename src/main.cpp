#include <iostream>
#include <string>
#include "event.hpp"

int main() {
    Event event;

    event.setName("CS410 Workshop");
    event.setCapacity(2);

    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if (event.registerParticipant(name)) {
        std::cout << "You have successfully signed up!"
                  << std::endl;
    } else {
        std::cout << "Signup failed."
                  << std::endl;
    }

    return 0;
}
