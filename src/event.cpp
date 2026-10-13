#include <iostream>
#include "event.hpp"

Event::Event() {
	this->startTime = (struct tm *)malloc(sizeof(struct tm));

	if (this->startTime == NULL) {
		std::cout << "Failed to allocate memory for startTime struct" << std::endl;
	}
	
	this->startTime->tm_min = 0;
	this->startTime->tm_hour = 0;
	this->startTime->tm_mday = 0;
	this->startTime->tm_mon = 0;
	this->startTime->tm_year = 0;
	
	this->endTime = (struct tm *)malloc(sizeof(struct tm));

	if (this->endTime == NULL) {
		std::cout << "Failed to allocate memory for endTime struct" << std::endl;
	}

	this->endTime->tm_min = 0;
	this->endTime->tm_hour = 0;
	this->endTime->tm_mday = 0;
	this->endTime->tm_mon = 0;
	this->endTime->tm_year = 0;
	
	this->duration = 0.0;
}

void Event::setName(std::string name) {
	this->name = name;
}

void Event::setCapacity(int capacity) {
	if (capacity > 0)
		this->capacity = capacity;
}

void Event::setStartTime(int minute, int hour, int day, int month, int year) {
	if (this->startTime == NULL) {
		std::cout << "startTime is NULL" << std::endl;
		return;
	}
	
	startTime->tm_min = minute;
	startTime->tm_hour = hour;
	startTime->tm_mday = day;
	startTime->tm_mon = month;
	startTime->tm_year = year - 1900;
}

void Event::setStartTime(struct tm* time) {
	if (time == NULL) {
		std::cout << "Time is NULL" << std::endl;
		return;
	}

	if (this->startTime == NULL) {
		std::cout << "startTime is NULL" << std::endl;
		return;
	}

	this->startTime = time;
}

void Event::setEndTime(int minute, int hour, int day, int month, int year) {
	if (this->endTime == NULL) {
		std::cout << "endTime is NULL" << std::endl;
		return;
	}
	
	endTime->tm_min = minute;
	endTime->tm_hour = hour;
	endTime->tm_mday = day;
	endTime->tm_mon = month;
	endTime->tm_year = year - 1900;
}

void Event::setEndTime(struct tm* time) {
	if (time == NULL) {
		std::cout << "Time is NULL" << std::endl;
		return;
	}

	if (this->endTime == NULL) {
		std::cout << "endTime is NULL" << std::endl;
		return;
	}

	this->endTime = time;
}
	
void Event::setLocation(std::string building, std::string room) {
	this->location.building = building;
	this->location.room = room;
}

void Event::setLocation(Location location) {
	this->location = location;
}
	
std::string Event::getName() { return this->name; }
int Event::getCapacity() { return this->capacity; }
struct tm* Event::getStartTime() { return this->startTime; }
struct tm* Event::getEndTime() { return this->endTime; }
Location Event::getLocation() { return this->location; }
	
double Event::getDurationDays() {
	double seconds;
	
	if (endTime->tm_min + endTime->tm_hour + endTime->tm_mday + endTime->tm_mon + endTime->tm_year != 0) {
		seconds = difftime(mktime(getEndTime()), mktime(getStartTime()));
		this->duration = seconds / 60 / 60 / 365;
	}

	return this->duration;
}
