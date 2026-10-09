#include <string>

#include "event.hpp"

Event::Event() {};

void Event::setName(std::string name) {
	this->name = name;
}
	
void Event::setDate(int year, int month, int day) {
	if (year >= 0)
		this->date.year = year;

	if (month > 0 && month <= 12)
		this->date.month = month;

	if (day > 0 && day <= 31)
		this->date.day = day;
}
	
void Event::setTime(int hour, int minute) {
	if (hour >= 0 && hour <= 23)
		this->time.hour = hour;

	if (minute >= 0 && minute <= 59)
		this->time.minute = minute;
}
	
void Event::setLocation(std::string building, std::string room) {
	this->location.building = building;
	this->location.room = room;
}
	
std::string Event::getName() { return this->name; }
Event::Date Event::getDate() { return this->date; }
Event::Time Event::getTime() { return this->time; }
Event::Location Event::getLocation() { return this->location; }
	
std::string getDuration() {
	return "test";
}
