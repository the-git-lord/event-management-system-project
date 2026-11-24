#ifndef USER_HPP
#define USER_HPP

#include <string>

#include "report.hpp"
#include "password.hpp"

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
    // The plain test password is never stored, only a salt and the salted hash
    std::string passwordSalt;
    std::string passwordHash;
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

    // Log in by checking the password against the hash saved in a password file
    bool login(const PasswordFile& file, std::string username, std::string password);

    // Save this user's username, salt and hash to a password file
    bool saveCredentials(PasswordFile& file) const;
    void logout();

    std::string getName() const;
    std::string getUsername() const;
    std::string getPasswordSalt() const;
    std::string getPasswordHash() const;
    Role getRole() const;
    bool isLoggedIn() const;

    // True if the user is an administrator, false otherwise
    bool hasAdminPrivileges() const;

    int getWarningCount() const;
    bool isBanned() const;

    // File a report about another user. Must be logged in.
    bool reportUser(ReportBoard& board, const User& reportedUser, ReportReason reason, std::string details = "");
    
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