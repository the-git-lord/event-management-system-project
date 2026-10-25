#include "testEventUserRegistrationHelperFunctions.hpp"

std::vector<User> createFiveParticipants() {
	std::vector<User> users;
	users.push_back(Participant("Steve", "steve001", "1234"));
	users.push_back(Participant("John", "john025", "5678"));
	users.push_back(Participant("Adit", "adit002", "1267"));
	users.push_back(Participant("Kesh", "kesh001", "passwd1"));
	users.push_back(Participant("Raghav", "raghav005", "greatness"));
	return users;
}
