#include <iostream>
#include <string>

#include "../headers/waitlist.hpp"

int main() {
    Waitlist waitlist;
    int choice = 0;
    std::string name;

    while (choice != 4) {
        std::cout << "=== Waitlist Menu ===" << std::endl;
        std::cout << "1. Add Participant" << std::endl;
        std::cout << "2. View Waitlist" << std::endl;
        std::cout << "3. Remove Participant" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (!std::cin) {
            std::cout << "Please enter a number." << std::endl;
            break;
        }

        if (choice == 1) {
            std::cout << "Enter participant name: ";
            std::cin >> name;

            waitlist.addParticipant(name);
            std::cout << name << " was added!" << std::endl;
        }
        else if (choice == 2) {
            waitlist.viewParticipants();
        }
        else if (choice == 3) {
            std::cout << "Enter participant name to remove: ";
            std::cin >> name;

            if (waitlist.removeParticipant(name)) {
                std::cout << name << " was removed!" << std::endl;
            }
            else {
                std::cout << "Participant not found." << std::endl;
            }
        }
        else if (choice == 4) {
            std::cout << "Goodbye!" << std::endl;
        }
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
