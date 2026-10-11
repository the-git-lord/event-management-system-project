#include <iostream>

#include "event.hpp"
#include "ui.hpp"

Event testEventCreation() {
	Event event = Event();

	event.setName("ISC Lab Meeting");
	event.setCapacity(30);
	event.setStartTime(34, 18, 31, 6, 2027);
	event.setEndTime(12, 9, 17, 10, 2028);
	event.setLocation("ISC", "5300");

	return event;
}

Event testEventGetter(Event event) {
	Event getted_event = Event();

	getted_event.setName(event.getName());
	getted_event.setCapacity(event.getCapacity());
	getted_event.setStartTime(event.getStartTime());
	getted_event.setEndTime(event.getEndTime());
	getted_event.setLocation(event.getLocation());

	return getted_event;
}

void testEventDisplay(Event event) {
	Display display_event = Display();
	
	std::cout << "Separate event display calls" << std::endl;
	display_event.eventName(event);
	display_event.eventCapacity(event);
	display_event.eventStartTime(event);
	display_event.eventEndTime(event);
	display_event.eventLocation(event);
	display_event.eventDurationDays(event);

	std::cout << std::endl;
	std::cout << "One event display call" << std::endl;
	display_event.displayEvent(event);
}

int main() {
	Event event1 = testEventCreation();
	Event event2 = testEventGetter(event1);

	std::cout << "Event1" << std::endl;
	testEventDisplay(event1);

	std::cout << "Event2" << std::endl;
	testEventDisplay(event2);
}
