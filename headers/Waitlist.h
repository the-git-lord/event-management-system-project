#include <string>
#include <queue>

class Waitlist {
private:
    std::queue<std::string> participants;
    int waitlistCapacity;

public:
    Waitlist();

    bool addParticipant(const std::string& name);
    bool removeParticipant(const std::string& name);
    bool hasParticipants() const;
    std::string getNextParticipant() const;
    int getSize() const;
};