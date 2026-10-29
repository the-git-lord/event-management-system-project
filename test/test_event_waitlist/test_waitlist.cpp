#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "event.hpp"
#include "testEventCreationHelperFunctions.hpp"

TEST(TestWaitlistHandling, WaitlistOverloaded) {
    Event event = createValidEvent();

    event.waitlist.addParticipant("Michael");
    event.waitlist.addParticipant("Alex");
    event.waitlist.addParticipant("Sarah");

    ASSERT_EQ(event.waitlist.getSize(), 3);
}

TEST(TestWaitlistHandling, WaitlistEmpty) {
    Event event = createValidEvent();

    ASSERT_EQ(event.waitlist.hasParticipants(), false);
    ASSERT_EQ(event.waitlist.getSize(), 0);
}

TEST(TestWaitlistFunctionality, WaitlistParticipantAddition) {
    Event event = createValidEvent();

    event.waitlist.addParticipant("Michael");

    ASSERT_EQ(event.waitlist.hasParticipants(), true);
    ASSERT_EQ(event.waitlist.getSize(), 1);
    ASSERT_EQ(event.waitlist.getNextParticipant(), "Michael");
}

TEST(TestWaitlistFunctionality, WaitlistParticipantRemoval) {
    Event event = createValidEvent();

    event.waitlist.addParticipant("Michael");
    event.waitlist.addParticipant("Alex");

    ASSERT_EQ(event.waitlist.removeParticipant("Michael"), true);
    ASSERT_EQ(event.waitlist.getSize(), 1);
    ASSERT_EQ(event.waitlist.getNextParticipant(), "Alex");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}