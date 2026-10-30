#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestWaitlistHandling, WaitlistOverloaded) {
    Event event = createValidEvent();

    User user = Participant("Michael", "A", "1");

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(event.Waitlist::addParticipant(user));
    }

    ASSERT_EQ(event.Waitlist::getSize(), 10);

    User extra = Participant("Alex", "B", "2");

    ASSERT_FALSE(event.Waitlist::addParticipant(extra));
    ASSERT_EQ(event.Waitlist::getSize(), 10);
}

TEST(TestWaitlistHandling, WaitlistEmpty) {
    Event event = createValidEvent();

    ASSERT_FALSE(event.Waitlist::hasParticipants());
    ASSERT_EQ(event.Waitlist::getSize(), 0);
}

TEST(TestWaitlistFunctionality, WaitlistParticipantAddition) {
    Event event = createValidEvent();

    User first = Participant("Michael", "A", "1");
    User second = Participant("Alex", "B", "2");

    ASSERT_TRUE(event.Waitlist::addParticipant(first));
    ASSERT_TRUE(event.Waitlist::addParticipant(second));

    ASSERT_EQ(event.Waitlist::getSize(), 2);

    ASSERT_STREQ(
        event.Waitlist::getNextParticipant().getName().c_str(),
        first.getName().c_str()
    );
}

TEST(TestWaitlistFunctionality, WaitlistParticipantRemoval) {
    Event event = createValidEvent();

    User first = Participant("Michael", "A", "1");
    User second = Participant("Alex", "B", "2");
    User third = Participant("Sarah", "C", "3");

    event.Waitlist::addParticipant(first);
    event.Waitlist::addParticipant(second);
    event.Waitlist::addParticipant(third);

    ASSERT_TRUE(event.Waitlist::removeParticipant(second));
    ASSERT_EQ(event.Waitlist::getSize(), 2);

    ASSERT_STREQ(
        event.Waitlist::getNextParticipant().getName().c_str(),
        first.getName().c_str()
    );

    ASSERT_TRUE(event.Waitlist::removeParticipant(first));

    ASSERT_STREQ(
        event.Waitlist::getNextParticipant().getName().c_str(),
        third.getName().c_str()
    );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}