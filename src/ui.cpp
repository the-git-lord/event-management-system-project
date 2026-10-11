#include <iostream>
#include <ctime>

#include "event.hpp"
#include "ui.hpp"

void Display::displayEvent(Event event) {
	eventName(event);
	eventCapacity(event);
	eventStartTime(event);
	eventEndTime(event);
	eventDurationDays(event);
	eventLocation(event);
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
