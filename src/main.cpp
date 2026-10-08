#include <iostream>

#include "event.hpp"

int main() {
	Event event = Event{};
	event.setName("Test Event!");
	// event.setDate(2026, 11, 31);
	// event.setTime(23, 59);
	// event.setLocation("McCormmack", "ISC");

	std::cout << event.getName() << std::endl;
	// std::cout << event.getDate() << std::endl;
	// std::cout << event.getTime() << std::endl;
	// std::cout << event.getLocation() << std::endl;
	
	return 0;
}
