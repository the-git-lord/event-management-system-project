#include <gtest/gtest.h>

#include "event.hpp"

TEST(TestWaitlistFunctionality, WaitlistParticipantAddition) {
	Event event = createValidEvent();
}

TEST(TestWaitlistFunctionality, WaitlistParticipantRemoval) {
	Event event = createValidEvent();
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
