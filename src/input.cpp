#include <iostream>
#include "input.hpp"

void UserInput::CreateEvent() {
	Event event = Event();
	std::string name;
	int capacity;
	int minute, hour, day, month, year;
	std::string building, room;
			
	std::cout << "Set Name: ";
	getline(std::cin, name);
	event.setName(name);
			
	std::cout << "Set Capacity: ";
	std::cin >> capacity;
	event.setCapacity(capacity);
			
	std::cout << "Set Start Time [M/H D/M/Y]: ";
	std::cin >> minute >> hour >> day >> month >> year;
	event.setStartTime(minute, hour, day, month, year);
			
	std::cout << "Set End Time [M/H D/M/Y]: ";
	std::cin >> minute >> hour >> day >> month >> year;
	event.setEndTime(minute, hour, day, month, year);

	std::cout << "Set Location [Building]: ";
	getline(std::cin, building);
	std::cout << "Set Location [Room]: ";
	getline(std::cin, room);
	event.setLocation(building, room);

	EventsList.push_back(event);
}

void UserInput::EditEvent() {

}
