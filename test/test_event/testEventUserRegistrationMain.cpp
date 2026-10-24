#include <gtest/gtest.h>

#include "event.hpp"
#include "user.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestEventUserRegistration, OverCapacity) {
	Event event = createValidEventOneCapacity();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_EQ(event.registerParticipant(user1), 0);
	ASSERT_EQ(event.registerParticipant(user2), 1);
}

TEST(TestEventUserRegistration, WithInCapacity) {
	Event event = createValidEvent();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_EQ(event.registerParticipant(user1), 0);
	ASSERT_EQ(event.registerParticipant(user2), 0);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
