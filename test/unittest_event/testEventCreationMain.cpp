#include <iostream>
#include <vector>
#include <gtest/gtest.h>

#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"
#include "testEventCheckHelperFunctions.hpp"

TEST(TestEvent, EventParameterBoundaries) {
	Event event = Event();
	struct tm *startTime = (struct tm *)malloc(sizeof(struct tm));
	struct tm *endTime = (struct tm *)malloc(sizeof(struct tm));
	
	event = createEventOutOfBounds();
	startTime = event.getStartTime();
	endTime = event.getEndTime();

	ASSERT_EQ(event.getCapacity(), 0);
	ASSERT_EQ(startTime->tm_min, 0);
	ASSERT_EQ(startTime->tm_hour, 0);
	ASSERT_EQ(startTime->tm_mday, 0);
	ASSERT_EQ(startTime->tm_mon, 0);
	ASSERT_EQ(startTime->tm_year, 0);

	ASSERT_EQ(endTime->tm_min, 0);
	ASSERT_EQ(endTime->tm_hour, 0);
	ASSERT_EQ(endTime->tm_mday, 0);
	ASSERT_EQ(endTime->tm_mon, 0);
	ASSERT_EQ(endTime->tm_year, 0);
}

TEST(TestEvent, EventSettersAndGetters) {
	Event event = Event();
	Event temp = Event();

	event = createValidEvent();
	temp = createValidEventCopy(event);
	
	ASSERT_TRUE(checkNameEqual(event, temp));
	ASSERT_TRUE(checkCapacityEqual(event, temp));
	ASSERT_TRUE(checkStartTimeEqual(event, temp));
	ASSERT_TRUE(checkEndTimeEqual(event, temp));
	ASSERT_TRUE(checkLocationEqual(event, temp));
}

int main() {
	return RUN_ALL_TESTS();
}
