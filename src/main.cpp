#include <iostream>

#include "include/events.hpp"
#include "include/ui.hpp"

int main() {
	int user_type = 0;
	DisplayDashboard dashboard = new DisplayDashboard();
	std::cout << "[1] Participant\t[2] Administrator" << std::endl;
	std::cout << ": ";
	std::cin >> user_type;

	dashboard.dashboard(user_type);
	sleep(1000);
	
	return 0;
}
