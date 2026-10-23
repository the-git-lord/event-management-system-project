#include <string>
#include "testEventCreationHelperFunctions.hpp"

Event createEventOutOfBounds() {
	Event event = Event();
	
	event.setName("Out of Bounds Event Happening Now");
	event.setCapacity(-234679);
	event.setStartTime(60, 25, 32, 13, 1899);
	event.setEndTime(61, 26, 33, 14, 1898);
	event.setLocation("In the incomprehensible void", "where there are no rooms");

	return event;
}

Event createValidEvent() {
	Event event = Event();
	
	event.setName("ISC Lab Meeting");
	event.setCapacity(30);
	event.setStartTime(11, 18, 29, 1, 2027);
	event.setEndTime(59, 11, 17, 10, 2030);
	event.setLocation("ISC", "5300");

	return event;
}

Event createValidEventCopy(Event& event) {
	Event copy = Event();
	
	copy.setName(event.getName());
	copy.setCapacity(event.getCapacity());
	copy.setStartTime(event.getStartTime());
	copy.setEndTime(event.getEndTime());
	copy.setLocation(event.getLocation());

	return copy;
}
