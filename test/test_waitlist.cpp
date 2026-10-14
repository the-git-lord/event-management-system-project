
#include "../headers/Waitlist.h"
#include <iostream>

using namespace std;

int main() {
    Waitlist waitlist;
    int choice = 0;
    string name;

    while (choice != 3) {
        cout << "=== Waitlist Menu ===" << endl;
        cout << "1. Add Participant" << endl;
        cout << "2. View Waitlist" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (!cin) {
            cout << "Please enter a number." << endl;
            break;
        }

        if (choice == 1) {
            cout << "Enter participant name: ";
            cin >> name;

            waitlist.addParticipant(name);
            cout << name << " was added!" << endl;
        }
        else if (choice == 2) {
            waitlist.viewParticipants();
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
