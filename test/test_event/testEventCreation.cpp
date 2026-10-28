#include <vector>
#include <gtest/gtest.h>

#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"
#include "testEventCheckHelperFunctions.hpp"

TEST(Event_Creation, Event_Time_Parameter_Boundaries) {
	Event event = Event();
	struct tm *startTime = (struct tm *)malloc(sizeof(struct tm));
	struct tm *endTime = (struct tm *)malloc(sizeof(struct tm));
	
	event = createEventOutOfBounds();
	startTime = event.getStartTime();
	endTime = event.getEndTime();

	ASSERT_TRUE(checkCapacityIsDefault(event));
	ASSERT_TRUE(checkTimeEqualDefault(startTime));
	ASSERT_TRUE(checkTimeEqualDefault(endTime));
}

TEST(Event_Creation, Event_Setters_And_Getters) {
	Event event = Event();
	Event temp = Event();

	event = createValidEvent();
	temp = createValidEventCopy(event);
	
	ASSERT_TRUE(checkEventEqual(event, temp));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
