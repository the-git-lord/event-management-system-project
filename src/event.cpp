#include <iostream>
#include "event.hpp"

Event::Event() {
    // Start with 0 capacity until it is set
    this->capacity = 0;

    this->startTime = (struct tm *)malloc(sizeof(struct tm));

	if (this->startTime == NULL) {
		std::cout << "Failed to allocate memory for startTime struct" << std::endl;
	}

	this->startTime->tm_sec = 0;
	this->startTime->tm_min = 0;
	this->startTime->tm_hour = 0;
	this->startTime->tm_mday = 0;
	this->startTime->tm_mon = 0;
	this->startTime->tm_year = 0;
	this->startTime->tm_isdst = 0;
	
	this->endTime = (struct tm *)malloc(sizeof(struct tm));

	if (this->endTime == NULL) {
		std::cout << "Failed to allocate memory for endTime struct" << std::endl;
	}

	this->endTime->tm_sec = 0;
	this->endTime->tm_min = 0;
	this->endTime->tm_hour = 0;
	this->endTime->tm_mday = 0;
	this->endTime->tm_mon = 0;
	this->endTime->tm_year = 0;
	this->endTime->tm_isdst = 0;
	
	this->duration = 0.0;
}

void Event::setMinute(struct tm *time, int minute) {
	if (minute >= 0 && minute <= 59)
		time->tm_min = minute;
}

void Event::setHour(struct tm *time, int hour) {
	if (hour >= 0 && hour <= 23)
		time->tm_hour = hour;
}

void Event::setDay(struct tm *time, int day) {
	if (day >= 1 && day <= 31)
		time->tm_mday = day;
}

void Event::setMonth(struct tm *time, int month) {
	if (month >= 1 && month <= 12)
		time->tm_mon = month;	
}

void Event::setYear(struct tm *time, int year) {
	if (year >= 1900)
		time->tm_year = year - 1900;
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

	setMinute(this->startTime, minute);
	setHour(this->startTime, hour);
	setDay(this->startTime, day);
	setMonth(this->startTime, month);
	setYear(this->startTime, year);
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
	
	setMinute(this->endTime, minute);
	setHour(this->endTime, hour);
	setDay(this->endTime, day);
	setMonth(this->endTime, month);
	setYear(this->endTime, year);
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
	if (endTime->tm_min + endTime->tm_hour + endTime->tm_mday + endTime->tm_mon + endTime->tm_year == 0) {
		return 0;
	}

	double seconds = difftime(mktime(getEndTime()), mktime(getStartTime()));
	this->duration = seconds / 60 / 60 / 365;

	return this->duration;
}


std::vector<std::string> Event::getParticipants() const {
    return participants;
}