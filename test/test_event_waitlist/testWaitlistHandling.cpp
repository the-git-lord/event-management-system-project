#include <gtest/gtest.h>

#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestWaitlistHandling, WaitlistOverloaded) {
	Event event = createValidEvent();
}

TEST(TestWaitlistHandling, WaitlistEmpty) {
	Event event = createValidEvent();
	ASSERT_EQ(event.Waitlist::hasParticipants(), 0);
}
