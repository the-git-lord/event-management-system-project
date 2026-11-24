#include "user.hpp"

User::User(std::string name, std::string username, std::string password, Role role) {
	this->name = name;
	this->username = username;
	this->passwordSalt = generateSalt();
	this->passwordHash = hashPassword(password, this->passwordSalt);
	this->role = role;
	this->loggedIn = false;
	this->warnings = 0;
	this->banned = false;
}

bool User::login(std::string username, std::string password) {
	// Hash what was typed with the user's salt and compare the hashes
	if (username == this->username && hashPassword(password, this->passwordSalt) == this->passwordHash) {
		this->loggedIn = true;
	} else {
		this->loggedIn = false;
	}

	return this->loggedIn;
}

bool User::login(const PasswordFile& file, std::string username, std::string password) {
	if (username == this->username && file.verify(username, password)) {
		this->loggedIn = true;
	} else {
		this->loggedIn = false;
	}

	return this->loggedIn;
}

bool User::saveCredentials(PasswordFile& file) const {
	return file.save(this->username, this->passwordSalt, this->passwordHash);
}

void User::logout() {
	this->loggedIn = false;
}

std::string User::getName() const {
	return this->name;
}

std::string User::getUsername() const {
	return this->username;
}

std::string User::getPasswordSalt() const {
	return this->passwordSalt;
}

std::string User::getPasswordHash() const {
	return this->passwordHash;
}

Role User::getRole() const {
	return this->role;
}

bool User::isLoggedIn() const {
	return this->loggedIn;
}

bool User::hasAdminPrivileges() const {
	return this-> loggedIn && this->role == Role::ADMINISTRATOR;
}

int User::getWarningCount() const {
	return this->warnings;
}

bool User::isBanned() const {
	return this->banned;
}

bool User::reportUser(ReportBoard& board, const User& reportedUser, ReportReason reason, std::string details) {

	if (!this->loggedIn) {
		return false;
	}

	int id = board.fileReport(this->username, reportedUser.getUsername(), reason, details);
	return id != -1;
}

Participant::Participant(std::string name, std::string username, std::string password)
	: User(name, username, password, Role::PARTICIPANT) {}
void Participant::setWorkshopType(WorkshopParticipantType type) {
    workshopType = type;
}

WorkshopParticipantType Participant::getWorkshopType() const {
    return workshopType;
}

void Participant::setConferenceType(ConferenceParticipantType type) {
    conferenceType = type;
}

ConferenceParticipantType Participant::getConferenceType() const {
    return conferenceType;
}

void Participant::setTrainingType(TrainingParticipantType type) {
    trainingType = type;
}

TrainingParticipantType Participant::getTrainingType() const {
    return trainingType;
}

void Participant::setCommunityType(CommunityParticipantType type) {
    communityType = type;
}

CommunityParticipantType Participant::getCommunityType() const {
    return communityType;
}