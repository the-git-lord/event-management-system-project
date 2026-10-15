#include <iostream>
#include <string>
#include <vector>

class Waitlist {
private:
    vector<string> participants;

public:
    void addParticipant(const std::string& name);
    void viewParticipants() const;
    bool removeParticipant(const std::string& name);
    bool hasParticipants() const;
	std::string getNextParticipant() const;
    int getSize() const;
};
