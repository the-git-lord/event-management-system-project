#include <gtest/gtest.h>
#include "user.hpp"

// Check that a new participant has no assigned categories.
TEST(ParticipantTypesTest, DefaultTypes) {
    Participant participant("Aditi", "aditi", "password");

    EXPECT_EQ(participant.getWorkshopType(),
              WorkshopParticipantType::NONE);
    EXPECT_EQ(participant.getConferenceType(),
              ConferenceParticipantType::NONE);
    EXPECT_EQ(participant.getTrainingType(),
              TrainingParticipantType::NONE);
    EXPECT_EQ(participant.getCommunityType(),
              CommunityParticipantType::NONE);
}

// Check workshop participant type.
TEST(ParticipantTypesTest, WorkshopType) {
    Participant participant("Aditi", "aditi", "password");

    participant.setWorkshopType(WorkshopParticipantType::STUDENT);

    EXPECT_EQ(participant.getWorkshopType(),
              WorkshopParticipantType::STUDENT);
}

// Check conference participant type.
TEST(ParticipantTypesTest, ConferenceType) {
    Participant participant("Aditi", "aditi", "password");

    participant.setConferenceType(ConferenceParticipantType::SPEAKER);

    EXPECT_EQ(participant.getConferenceType(),
              ConferenceParticipantType::SPEAKER);
}

// Check training participant type.
TEST(ParticipantTypesTest, TrainingType) {
    Participant participant("Aditi", "aditi", "password");

    participant.setTrainingType(TrainingParticipantType::TRAINEE);

    EXPECT_EQ(participant.getTrainingType(),
              TrainingParticipantType::TRAINEE);
}

// Check community participant type.
TEST(ParticipantTypesTest, CommunityType) {
    Participant participant("Aditi", "aditi", "password");

    participant.setCommunityType(CommunityParticipantType::VOLUNTEER);

    EXPECT_EQ(participant.getCommunityType(),
              CommunityParticipantType::VOLUNTEER);
}

// Check that changing one type does not affect the others.
TEST(ParticipantTypesTest, IndependentTypes) {
    Participant participant("Aditi", "aditi", "password");

    participant.setWorkshopType(WorkshopParticipantType::INSTRUCTOR);

    EXPECT_EQ(participant.getWorkshopType(),
              WorkshopParticipantType::INSTRUCTOR);
    EXPECT_EQ(participant.getConferenceType(),
              ConferenceParticipantType::NONE);
    EXPECT_EQ(participant.getTrainingType(),
              TrainingParticipantType::NONE);
    EXPECT_EQ(participant.getCommunityType(),
              CommunityParticipantType::NONE);
}