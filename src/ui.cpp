#include <iostream>
#include <ctime>
#include <vector>

#include "event.hpp"
#include "ui.hpp"

void Display::EventListTable(std::vector<Event> EventVector) {
	std::cout << "| Event Name                             "; 
	std::cout << "| Capacity ";
	std::cout << "| Start Time          ";
	std::cout << "| End Time            ";
	std::cout << "| Location            ";
	
	for (Event curr : EventVector) {
		eventName(curr);
		eventCapacity(curr);
		eventStartTime(curr);
		eventEndTime(curr);
		eventDurationDays(curr);
		eventLocation(curr);
	}
}

void Display::eventName(Event event) {
	std::cout << "Name: " << event.getName() << std::endl;
}

void Display::eventCapacity(Event event) {
	std::cout << "Capacity: " << event.getCapacity() << std::endl;
}

void Display::eventStartTime(Event event) {
	std::cout << "Start: " << asctime(event.getStartTime()) << std::endl;
}

void Display::eventEndTime(Event event) {
	std::cout << "End: " << asctime(event.getEndTime()) << std::endl;
}

void Display::eventLocation(Event event) {
	Location location = event.getLocation();
	std::cout << location.building << " " << location.room << std::endl;
}

void Display::eventDurationDays(Event event) {
	std::cout << "Days: " << event.getDurationDays() << std::endl;
}
