#include <iostream>
#include <string>
#include <vector>

#include "user.hpp"

class Waitlist {
private:
	std::vector<User> participants;

public:
	Waitlist();
	
    void addParticipant(const User name);
    void viewParticipants() const;
    bool removeParticipant(const User name);
    bool hasParticipants() const;
	std::string getNextParticipant() const;
    int getSize() const;
};
