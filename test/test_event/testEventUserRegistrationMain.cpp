#include <vector>
#include <forward_list>
#include <gtest/gtest.h>

#include "event.hpp"
#include "user.hpp"
#include "testEventCreationHelperFunctions.hpp"
#include "testEventUserRegistrationHelperFunctions.hpp"

TEST(TestEventUserRegistration, Over_Capacity) {
	Event event = createValidEventOneCapacity();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_EQ(event.addParticipant(user1), RegisterCode::ADDED_TO_EVENT);
	ASSERT_EQ(event.addParticipant(user2), RegisterCode::ADDED_TO_WAITLIST);
}

TEST(TestEventUserRegistration, Within_Capacity) {
	Event event = createValidEvent();
	Participant user1 = Participant("Steve", "steve001", "1234");
	Participant user2 = Participant("John", "john025", "5678");

	ASSERT_EQ(event.addParticipant(user1), RegisterCode::ADDED_TO_EVENT);
	ASSERT_EQ(event.addParticipant(user2), RegisterCode::ADDED_TO_EVENT);
}

TEST(TestEventUserRegistration, Event_Enrolled_User_Count_Match) {
	int enrolled = 0;
	
	Event event = createValidEvent();
	std::vector<User> fiveUsers = createFiveParticipants();
	for (User user : fiveUsers) {
		event.addParticipant(user);
	}

	std::forward_list<User> participants = event.getParticipants();
	for (User user : participants) {
		enrolled++;
	}

	ASSERT_EQ(event.getEnrolledSize(), enrolled);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
