#include <vector>
#include <gtest/gtest.h>

#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"
#include "testEventCheckHelperFunctions.hpp"

TEST(TestEventCreation, Event_Time_Parameter_Boundaries) {
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

TEST(TestEventCreation, Event_Setters_And_Getters) {
	Event event = Event();
	Event temp = Event();

	event = createValidEvent();
	temp = createValidEventCopy(event);
	
	ASSERT_TRUE(checkEventEqual(event, temp));
}
TEST(TestEventCreation, Correct_Month) {
    Event event;

    // November should be stored as 10 in C++.
    event.setStartTime(0, 10, 24, 11, 2026);
    ASSERT_EQ(event.getStartTime()->tm_mon, 10);

    // December should be stored as 11.
    event.setStartTime(0, 10, 24, 12, 2026);
    ASSERT_EQ(event.getStartTime()->tm_mon, 11);
}

TEST(TestEventCreation, Correct_Duration) {
    Event event;

    // Workshop starts at 10 AM.
    event.setStartTime(0, 10, 24, 11, 2026);

    // Workshop ends at 12 PM.
    event.setEndTime(0, 12, 24, 11, 2026);

    // Two hours should equal 2/24 days.
    ASSERT_NEAR(event.getDurationDays(), 2.0 / 24.0, 0.0001);
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
