#include <iostream>
#include <string>
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
		std::cout << "[9] Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "Command: ";
		std::cin >> option;
		std::cin.ignore();

		switch (option) {
		case 1: {
			Display::EventListTable();
			break;
		}
		case 2: {
			UserInput::CreateEvent();
			break;
		}
		case 3: {
			UserInput::EditEvent();
			break;
		}
		case 9: {
			std::cout << "Exiting" << std::endl;
			return 0;
		}
		}
	}
	
	return 0;
}
