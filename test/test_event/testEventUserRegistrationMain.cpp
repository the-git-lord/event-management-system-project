#include <gtest/gtest.h>

#include "event.hpp"
#include "user.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestEventUserRegistration, OverCapacity) {
	Event event = createValidEventOneCapacity();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_EQ(event.registerParticipant(user1), RegisterCode::ADDED_TO_EVENT);
	ASSERT_EQ(event.registerParticipant(user2), RegisterCode::ADDED_TO_WAITLIST);
}

TEST(TestEventUserRegistration, WithInCapacity) {
	Event event = createValidEvent();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_EQ(event.registerParticipant(user1), RegisterCode::ADDED_TO_EVENT);
	ASSERT_EQ(event.registerParticipant(user2), RegisterCode::ADDED_TO_EVENT);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
