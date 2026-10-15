#include <cassert>
#include <iostream>
#include "event.hpp"

int main() {
    Event event;
    event.setCapacity(2);

    // Check if participants can sign up
    assert(event.registerParticipant("Aditi"));
    assert(event.registerParticipant("Kesh"));

    // Check if the event is full
    assert(!event.registerParticipant("Steve"));

    // Check if an empty name is rejected
    assert(!event.registerParticipant(""));

    // Check if both names are saved in the list
    assert(event.getParticipants().size() == 2);
    assert(event.getParticipants()[0] == "Aditi");
    assert(event.getParticipants()[1] == "Kesh");

    std::cout << "All participant signup tests passed!"
              << std::endl;

    return 0;
} 