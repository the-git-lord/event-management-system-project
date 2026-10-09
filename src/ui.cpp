#include <iostream>

class Display {
private:
	const string months[] = {"January", "February", "March", "April",
							 "May", "June", "July", "August",
							 "September", "October", "November", "December"};
	
private:
	void AdminDashboard() {
		std::cout << "aaaaaaaaaaaaaaaaaaaa" << std::endl;
	}

	void ParticipantDashboard() {
		std::cout << "bbbbbbbbbbbbbbbbbbbb" << std::endl;
	}

private:
	void printEventName(string name) {

	}
	
	void printEventDate(Date date) {

	}

	void printEventTime(Time time) {
		
	}

	void printEventLocation(Location location) {
		
	}
	
public:
	Display() {
	}
	
	void printDashboard(User user) {
		if (dynamic_cast<Participant*>(user) != nullptr) {
			ParticipantDashboard();
		} else if (dynamic_cast<Administrator*>(user) != nullptr) {
			AdminDashboard();
		}
	}
	
	void printEvent(Event event) {
		printEventName(event.getName());
		printEventDate(event.getDate());
		printEventTime(event.getTime());
		printEventLocation(event.getLocation());
	}
};
