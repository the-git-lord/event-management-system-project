#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Waitlist {
private:
    vector<string> participants;

public:
    void addParticipant(const string& name);
    void viewParticipants() const;
    bool removeParticipant(const string& name);
    bool hasParticipants() const;
    string getNextParticipant() const;
    int getSize() const;
};