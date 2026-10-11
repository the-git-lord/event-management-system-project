#include <iostream>
#include <vector>

#include "event.hpp"
#include "ui.hpp"

int main() {
	std::vector<Event> EventsList = {};

	while (true) {
		int option = -1;
		
		std::cout << "[1] Display Events" << std::endl;
		std::cout << "[2] Create Event" << std::endl;
		std::cout << "[3] Edit Event" << std::endl;
		std::cout << "[0] Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "Command: ";
		std::cin >> option;
		std::cin.ignore();

		switch (option) {
		case 1: {
			for (Event event : EventsList) {
				Display::eventName(event);
			}
			break;
		}
		case 2: {
			Event event = Event();
			std::string name;
			
			std::cout << "Set Name: ";
			std::cin >> name;

			event.setName(name);
			EventsList.push_back(event);
			
			break;
		}
		case 3: {
			std::cout << "Pick Event to Edit: ";
			
			break;
		}
		case 0: {
			std::cout << "Exiting" << std::endl;
			return 0;
		}
		}
	}
	
	return 0;
}
