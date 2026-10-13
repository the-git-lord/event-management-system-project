#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Stores all the information about an event
struct Event {
    string name;
    string date;
    string location;
    int capacity;
    vector<string> participants;

    // Stores the names of participants waiting for a spot
    vector<string> waitlist;
};

// This code should add the participants to the waitlist
void addToWaitlist(Event& event, const string& participantName) {
    
    // Checks if the event has reached its maximum capacity
    if (event.participants.size() >= event.capacity) {

        // Adds the participant to the end of the waitlist
        event.waitlist.push_back(participantName);

        cout << participantName
             << " was added to the waitlist." << endl;

    } else {
        cout << "The event still has available spots." << endl;
    }
}

// This will display all the participants that is on the waitlist
void viewWaitlist(Event &event){
    cout << "=== Waitlist ===" << endl;

    // This should check if nobody is on the waitlist
    if (event.waitlist.empty()){
        cout << "The waitlist is empty." << endl;
        return;
    }
    
    // Goes through the waitlist and displays each participant
    for (int i = 0; i < event.waitlist.size(); i++){
        cout << i + 1 << ". " << event.waitlist[i] << endl;
    }
}

// Moves the first waiting participant into the event
void moveFromWaitlist(Event &event) {

    // Checks if a spot is available and someone is waiting
    if (event.participants.size() < event.capacity &&
        !event.waitlist.empty()) {

        // Gets the first participant on the waitlist
        string participantName = event.waitlist[0];

        // Adds the participant to the event
        event.participants.push_back(participantName);

        // Removes the participant from the waitlist
        event.waitlist.erase(event.waitlist.begin());

        cout << participantName << " was moved into the event." << endl;

    } else {
        cout << "No available spot or the waitlist is empty." << endl;
    }
}

int main() {
   
    // Creates an event for testing
    Event event;
    event.capacity = 2;

    // Adds two people so the event is full
    event.participants.push_back("Michael");
    event.participants.push_back("Alex");

    int choice = 0;
    string name;

    // Keeps the menu running until the user chooses Exit
    while (choice != 3) {

        // Displays the menu
        cout << "=== Waitlist Management ===" << endl;
        cout << "1. Join Waitlist" << endl;
        cout << "2. View Waitlist" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        // Stops the program if the input is not a number
        if (!cin) {
            cout << "Please enter a number." << endl;
            break;
        }

        // Allows a participant to enter their name
        if (choice == 1) {
            cout << "Enter your name: ";
            cin >> name;

            addToWaitlist(event, name);
        }

        // Shows everyone on the waitlist
        if (choice == 2) {
            viewWaitlist(event);
        }
    }

    return 0;
}