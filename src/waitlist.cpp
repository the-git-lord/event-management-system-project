#include "../headers/Waitlist.h"

using namespace std;

void Waitlist::addParticipant(const string& name) {
    participants.push_back(name);
}

void Waitlist::viewParticipants() const {
    if (participants.empty()) {
        cout << "The waitlist is empty." << endl;
        return;
    }

    for (int i = 0; i < participants.size(); i++) {
        cout << i + 1 << ". " << participants[i] << endl;
    }
}

bool Waitlist::removeParticipant(const string& name) {
    for (int i = 0; i < participants.size(); i++) {
        if (participants[i] == name) {
            participants.erase(participants.begin() + i);
            return true;
        }
    }

    return false;
}

bool Waitlist::hasParticipants() const {
    return !participants.empty();
}

string Waitlist::getNextParticipant() const {
    if (participants.empty()) {
        return "";
    }

    return participants[0];
}

int Waitlist::getSize() const {
    return participants.size();
}