#include <iostream>
#include <vector>
#include <gtest/gtest.h>

#include "event.hpp"
#include "ui.hpp"

TEST(TestEvent, EventParameterOutsideBoundaries) {

}

TEST(TestEvent, EventParameterInsideBoundaries) {

}

TEST(TestEvent, EventSettersAndGetters) {
	std::vector<Event> EventVector = {};
	Event event = Event();
	Event temp = Event();

	event.setName("ISC Lab Meeting");
	event.setCapacity(30);
	event.setStartTime(34, 18, 40, 6, 2027);
	event.setEndTime(12, 9, 17, 10, 2028);
	event.setLocation("ISC", "5300");

	temp.setName(event.getName());
	temp.setCapacity(event.getCapacity());
	temp.setStartTime(event.getStartTime());
	temp.setEndTime(event.getEndTime());
	temp.setLocation(event.getLocation());

	
}

int main() {

}
