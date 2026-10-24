#include <iostream>
#include <string>
#include <gtest/gtest.h>

#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestWaitlistHandling, WaitlistOverloaded) {

}

TEST(TestWaitlistHandling, WaitlistEmpty) {
	Event event = createValidEvent();
	ASSERT_EQ(event.Waitlist::hasParticipants(), 0);
}

TEST(TestWaitlistFunctionality, WaitlistParticipantAddition) {
	Event event = createValidEvent();
	
}

TEST(TestWaitlistFunctionality, WaitlistParticipantRemoval) {

}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
