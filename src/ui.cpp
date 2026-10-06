#include <iostream>

class DisplayDashboard {

private:
	void AdminDashboard() {
		std::cout << "aaaaaaaaaaaaaaaaaaaa" << std::endl;
	}

	void ParticipantDashboard() {
		std::cout << "bbbbbbbbbbbbbbbbbbbb" << std::endl;
	}

public:
	DisplayDashboard() {
	}
	
	void dashboard(int user_type) {
		if (user_type == 1) {
			ParticipantDashboard();
		} else if (user_type == 2) {
			AdminDashboard();
		}
	}
}
