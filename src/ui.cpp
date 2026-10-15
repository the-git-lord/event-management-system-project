#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>

#include "event.hpp"
#include "ui.hpp"

void DisplayEvent::EventListTable(std::vector<Event> EventVector) {
	DisplayEvent title = DisplayEvent();
	title.printTableColumnTitles();
	
	for (Event curr : EventVector) {
		EventEntry(curr);
	}
}

void DisplayEvent::EventEntry(Event event) {
	DisplayEvent retrievers = DisplayEvent();
	
	retrievers.name(event);
	std::cout << "\t";
	retrievers.capacity(event);
	std::cout << "\t";
	retrievers.startTime(event);
	std::cout << "\t";
	retrievers.endTime(event);
	std::cout << "\t";
	retrievers.durationDays(event);
	std::cout << "\t";
	retrievers.location(event);
	std::cout << std::endl;	
}

void DisplayEvent::name(Event event) {
	std::cout << event.getName();
}

void DisplayEvent::capacity(Event event) {
	std::cout << event.getCapacity();
}

void DisplayEvent::startTime(Event event) {
	time_t mktime_var = mktime(event.getStartTime());
	char* formatted_time = ctime(&mktime_var);
	formatted_time[strlen(formatted_time) - 1] = '\0';
	std::cout << formatted_time;
}

void DisplayEvent::endTime(Event event) {
	time_t mktime_var = mktime(event.getEndTime());
	char* formatted_time = ctime(&mktime_var);
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

void DisplayEvent::printTableColumnTitles() {
	std::cout << "| Event Name                             "; 
	std::cout << "| Capacity ";
	std::cout << "| Start Time          ";
	std::cout << "| End Time            ";
	std::cout << "| Location                               |" << std::endl;
}
