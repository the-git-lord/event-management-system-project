#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>

#include "event.hpp"
#include "ui.hpp"

void DisplayEvent::EventListTable(std::vector<Event> EventVector) {
	DisplayEvent retrievers = DisplayEvent();
	
	std::cout << "| Event Name                             "; 
	std::cout << "| Capacity ";
	std::cout << "| Start Time          ";
	std::cout << "| End Time            ";
	std::cout << "| Location                               |" << std::endl;
	
	for (Event curr : EventVector) {
		retrievers.name(curr);
		std::cout << "\t";
		retrievers.capacity(curr);
		std::cout << "\t";
		retrievers.startTime(curr);
		std::cout << "\t";
		retrievers.endTime(curr);
		std::cout << "\t";
		retrievers.durationDays(curr);
		std::cout << "\t";
		retrievers.location(curr);
		std::cout << std::endl;
	}
}

void DisplayEvent::name(Event event) {
	std::cout << event.getName();
}

void DisplayEvent::capacity(Event event) {
	std::cout << event.getCapacity();
}

void DisplayEvent::startTime(Event event) {
	char* formatted_time = asctime(event.getStartTime());
	formatted_time[strlen(formatted_time) - 1] = '\0';
	std::cout << formatted_time;
}

void DisplayEvent::endTime(Event event) {
	char* formatted_time = asctime(event.getEndTime());
	formatted_time[strlen(formatted_time) - 1] = '\0';
	std::cout << formatted_time;
}

void DisplayEvent::location(Event event) {
	Location location = event.getLocation();
	std::cout << location.building << " " << location.room;
}

void DisplayEvent::durationDays(Event event) {
	std::cout << event.getDurationDays();
}
