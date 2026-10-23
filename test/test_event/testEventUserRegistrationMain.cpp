#include <gtest/gtest.h>

#include "event.hpp"
#include "user.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestEventUserRegistration, OverCapacity) {
	Event event = createValidEventOneCapacity();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_TRUE(event.registerParticipant(user1));
	ASSERT_FALSE(event.registerParticipant(user2));
}

TEST(TestEventUserRegistration, WithInCapacity) {
	Event event = createValidEvent();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_TRUE(event.registerParticipant(user1));
	ASSERT_TRUE(event.registerParticipant(user2));
}

int main() {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
