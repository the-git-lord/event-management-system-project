#ifndef USER_HPP
#define USER_HPP

#include <string>

enum class Role {
    PARTICIPANT,
    ADMINISTRATOR
};
enum class WorkshopParticipantType {
    NONE,
    STUDENT,
    BEGINNER,
    PROFESSIONAL,
    INSTRUCTOR
};

enum class ConferenceParticipantType {
    NONE,
    RESEARCHER,
    PROFESSOR,
    SPEAKER,
    ATTENDEE
};

enum class TrainingParticipantType {
    NONE,
    EMPLOYEE,
    TRAINEE,
    TRAINER
};

enum class CommunityParticipantType {
    NONE,
    VOLUNTEER,
    RESIDENT,
    ORGANIZER,
    ATTENDEE
};
class User {
protected:
    std::string name;
    std::string username;
    std::string password;
    Role role;
    bool loggedIn;

private:
    // Only an Administrator can change these (see friend below)
    int warnings;
    bool banned;

    friend class Administrator;

public:
    User(std::string name, std::string username, std::string password, Role role);
    virtual ~User() = default;

    bool login(std::string username, std::string password);
    void logout();

    std::string getName() const;
    std::string getUsername() const;
    Role getRole() const;
    bool isLoggedIn() const;

    // True if the user is an administrator, false otherwise
    bool hasAdminPrivileges() const;

    int getWarningCount() const;
    bool isBanned() const;
};



class Participant : public User {
private:
    WorkshopParticipantType workshopType = WorkshopParticipantType::NONE;
    ConferenceParticipantType conferenceType = ConferenceParticipantType::NONE;
    TrainingParticipantType trainingType = TrainingParticipantType::NONE;
    CommunityParticipantType communityType = CommunityParticipantType::NONE;
public:
    Participant(std::string name, std::string username, std::string password);

void setWorkshopType(WorkshopParticipantType type);
WorkshopParticipantType getWorkshopType() const;

void setConferenceType(ConferenceParticipantType type);
ConferenceParticipantType getConferenceType() const;

void setTrainingType(TrainingParticipantType type);
TrainingParticipantType getTrainingType() const;

void setCommunityType(CommunityParticipantType type);
CommunityParticipantType getCommunityType() const;

};
#endif