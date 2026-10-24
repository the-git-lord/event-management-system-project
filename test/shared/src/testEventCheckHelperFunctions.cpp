#include "testEventCheckHelperFunctions.hpp"

bool checkEventEqual(Event& event1, Event& event2) {
	if (!checkNameEqual(event1, event2))
		return false;
	
	if (!checkCapacityEqual(event1, event2))
		return false;
	
	if (!checkStartTimeEqual(event1, event2))
		return false;
	
	if (!checkEndTimeEqual(event1, event2))
		return false;
	
	if (!checkLocationEqual(event1, event2))
		return false;

	return true;
}

bool checkNameEqual(Event& event1, Event& event2) {
	std::string event1_name = event1.getName();
	std::string event2_name = event2.getName();
	
	return (event1_name.compare(event2_name) == 0);
}

bool checkCapacityEqual(Event& event1, Event& event2) {
	return (event1.getCapacity() == event2.getCapacity());
}

bool checkStartTimeEqual(Event& event1, Event& event2) {
	struct tm *event1_startTime = (struct tm*)malloc(sizeof(struct tm));
	struct tm *event2_startTime = (struct tm*)malloc(sizeof(struct tm));

	event1_startTime = event1.getStartTime();
	event2_startTime = event2.getStartTime();

	if (event1_startTime->tm_min != event2_startTime->tm_min)
		return false;
	
	if (event1_startTime->tm_hour != event2_startTime->tm_hour)
		return false;
	
	if (event1_startTime->tm_mday != event2_startTime->tm_mday)
		return false;
	
	if (event1_startTime->tm_mon != event2_startTime->tm_mon)
		return false;
	
	if (event1_startTime->tm_year != event2_startTime->tm_year)
		return false;

	return true;
}

bool checkEndTimeEqual(Event& event1, Event& event2) {
	struct tm *event1_endTime = (struct tm*)malloc(sizeof(struct tm));
	struct tm *event2_endTime = (struct tm*)malloc(sizeof(struct tm));

	event1_endTime = event1.getEndTime();
	event2_endTime = event2.getEndTime();

	if (event1_endTime->tm_min != event2_endTime->tm_min)
		return false;
	
	if (event1_endTime->tm_hour != event2_endTime->tm_hour)
		return false;
	
	if (event1_endTime->tm_mday != event2_endTime->tm_mday)
		return false;
	
	if (event1_endTime->tm_mon != event2_endTime->tm_mon)
		return false;
	
	if (event1_endTime->tm_year != event2_endTime->tm_year)
		return false;

	return true;
}

bool checkLocationEqual(Event& event1, Event& event2) {
	Location event1_location = event1.getLocation();
	Location event2_location = event2.getLocation();

	if (event1_location.building.compare(event2_location.building) != 0)
		return false;

	if (event1_location.room.compare(event2_location.room) != 0)
		return false;

	return true;
}

bool checkCapacityIsDefault(Event& event) {
	return (event.getCapacity() == 0);
}

bool checkTimeEqualDefault(struct tm *time) {
	if (time->tm_min != 0)
		return false;
	
	if (time->tm_hour != 0)
		return false;
	
	if (time->tm_mday != 0)
		return false;
	
	if (time->tm_mon != 0)
		return false;
	
	if (time->tm_year != 0)
		return false;

	return true;
}
