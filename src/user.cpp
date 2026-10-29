#include "user.hpp"

User::User(std::string name, std::string username, std::string password, Role role) {
	this->name = name;
	this->username = username;
	this->password = password;
	this->role = role;
	this->loggedIn = false;
}

bool User::login(std::string username, std::string password) {
	// TODO: store a hashed password instead of the plain text password
	if (username == this->username && password == this->password) {
		this->loggedIn = true;
	} else {
		this->loggedIn = false;
	}

	return this->loggedIn;
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

Role User::getRole() const {
	return this->role;
}

bool User::isLoggedIn() const {
	return this->loggedIn;
}

bool User::hasAdminPrivileges() const {
	return this-> loggedIn && this->role == Role::ADMINISTRATOR;
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