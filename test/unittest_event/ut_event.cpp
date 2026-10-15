#include <iostream>
#include <vector>

#include "event.hpp"
#include "ui.hpp"

Event testEventSetters() {
	Event event = Event();

	event.setName("ISC Lab Meeting");
	event.setCapacity(30);
	event.setStartTime(34, 18, 40, 6, 2027);
	event.setEndTime(12, 9, 17, 10, 2028);
	event.setLocation("ISC", "5300");

	return event;
}

Event testEventGetters(Event event) {
	Event temp = Event();

	temp.setName(event.getName());
	temp.setCapacity(event.getCapacity());
	temp.setStartTime(event.getStartTime());
	temp.setEndTime(event.getEndTime());
	temp.setLocation(event.getLocation());

	return temp;
}

void testEventDisplay(std::vector<Event> EventVector) {
	DisplayEvent::EventListTable(EventVector);
}

int main() {
	std::vector<Event> EventVector = {};
	Event event1 = testEventSetters();
	Event event2 = testEventGetters(event1);
	Event event3 = testEventGetters(event2);
	Event event4 = testEventGetters(event3);
	Event event5 = testEventGetters(event4);
	EventVector.push_back(event1);
	EventVector.push_back(event2);
	EventVector.push_back(event3);
	EventVector.push_back(event4);
	EventVector.push_back(event5);

	testEventDisplay(EventVector);
}
