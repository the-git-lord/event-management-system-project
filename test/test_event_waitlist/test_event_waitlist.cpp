#include <gtest/gtest.h>
#include "../headers/Waitlist.h"

TEST(TestWaitlistHandling, WaitlistOverloaded) {
    Waitlist waitlist;

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(waitlist.addParticipant("Michael"));
    }

    ASSERT_EQ(waitlist.getSize(), 10);
    ASSERT_FALSE(waitlist.addParticipant("Alex"));
    ASSERT_EQ(waitlist.getSize(), 10);
}

TEST(TestWaitlistHandling, WaitlistEmpty) {
    Waitlist waitlist;

    ASSERT_FALSE(waitlist.hasParticipants());
    ASSERT_EQ(waitlist.getSize(), 0);
}

TEST(TestWaitlistFunctionality, WaitlistParticipantAddition) {
    Waitlist waitlist;

    ASSERT_TRUE(waitlist.addParticipant("Michael"));
    ASSERT_TRUE(waitlist.hasParticipants());
    ASSERT_EQ(waitlist.getSize(), 1);
    ASSERT_STREQ(waitlist.getNextParticipant().c_str(), "Michael");
}

TEST(TestWaitlistFunctionality, WaitlistParticipantRemoval) {
    Waitlist waitlist;

    waitlist.addParticipant("Michael");
    waitlist.addParticipant("Alex");

    ASSERT_TRUE(waitlist.removeParticipant("Michael"));
    ASSERT_EQ(waitlist.getSize(), 1);
    ASSERT_STREQ(waitlist.getNextParticipant().c_str(), "Alex");
    ASSERT_FALSE(waitlist.removeParticipant("Michael"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
