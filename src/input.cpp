#include <iostream>
#include <vector>

#include "event.hpp"
#include "input.hpp"

void EventEditInput::createEvent(std::vector<Event>& EventVector) {
	Event event = Event();
	EventEditInput setter = EventEditInput();
			
	setter.setName(event);
	setter.setCapacity(event);
	setter.setStartTime(event);
	setter.setEndTime(event);
	setter.setLocation(event);

	EventVector.push_back(event);
}

void EventEditInput::setName(Event& event) {
	std::string name;
	
	std::cout << "Set Name: ";
	getline(std::cin, name);
	event.setName(name);
}

void EventEditInput::setCapacity(Event& event) {
	int capacity;
	
	std::cout << "Set Capacity: ";
	std::cin >> capacity;
	event.setCapacity(capacity);
}

void EventEditInput::setStartTime(Event& event) {
	int minute, hour, day, month, year;
	
	std::cout << "Set Start Time [M/H D/M/Y]: ";
	std::cin >> minute >> hour >> day >> month >> year;
	std::cin.ignore();
	event.setStartTime(minute, hour, day, month, year);
}

void EventEditInput::setEndTime(Event& event) {
	int minute, hour, day, month, year;

	std::cout << "Set End Time [M/H D/M/Y]: ";
	std::cin >> minute >> hour >> day >> month >> year;
	std::cin.ignore();
	event.setEndTime(minute, hour, day, month, year);
}

void EventEditInput::setLocation(Event& event) {
	std::string building, room;
	
	std::cout << "Set Location [Building]: ";
	std::getline(std::cin, building);
	
	std::cout << "Set Location [Room]: ";
	std::getline(std::cin, room);
	event.setLocation(building, room);
}

void EventEditInput::chooseEventToEdit(std::vector<Event>& EventVector) {
	int choice = -1;
	
	for (std::vector<Event>::size_type i = 0; i < EventVector.size(); i++)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << ": ";
	std::cin >> choice;
	EventEditInput::editEvent(EventVector.at(choice));
}

void EventEditInput::editEvent(Event& event) {
	EventEditInput setter = EventEditInput();
	
	while (true) {
		int option = -1;
		
		std::cout << "[1] Set Name" << std::endl;
		std::cout << "[2] Set Capacity" << std::endl;
		std::cout << "[3] Set Start Time" << std::endl;
		std::cout << "[4] Set End Time" << std::endl;
		std::cout << "[5] Set Location" << std::endl;
		std::cout << "[9] Finish" << std::endl;
		std::cout << std::endl;
		std::cout << "Command: ";

		std::cin >> option;
		std::cin.ignore();

		switch (option) {
		case 1:
			setter.setName(event);
			break;
		case 2:
			setter.setCapacity(event);
			break;
		case 3:
			setter.setStartTime(event);
			break;
		case 4:
			setter.setEndTime(event);
			break;
		case 5:
			setter.setLocation(event);
			break;
		case 9:
			return;
		}
	}
}
