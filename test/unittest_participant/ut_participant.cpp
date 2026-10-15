
#include <cassert>
#include <iostream>
#include "event.hpp"
#include "user.hpp"

void testSignup() {
    Event event;
    event.setCapacity(2);

    Participant aditi("Aditi");
    Participant kesh("Kesh");

    assert(aditi.registerParticipant(event));
    assert(kesh.registerParticipant(event));
}

void testFullEvent() {
    Event event;
    event.setCapacity(1);

    Participant aditi("Aditi");
    Participant kesh("Kesh");

    assert(aditi.registerParticipant(event));
    assert(!kesh.registerParticipant(event));
}

void testEmptyName() {
    Event event;
    event.setCapacity(2);

    Participant participant("");

    assert(!participant.registerParticipant(event));
}

void testParticipantList() {
    Event event;
    event.setCapacity(2);

    Participant aditi("Aditi");
    Participant kesh("Kesh");

    aditi.registerParticipant(event);
    kesh.registerParticipant(event);

    assert(event.getParticipants().size() == 2);
    assert(event.getParticipants()[0] == "Aditi");
    assert(event.getParticipants()[1] == "Kesh");
}

int main() {
    testSignup();
    testFullEvent();
    testEmptyName();
    testParticipantList();

    std::cout << "All participant signup tests passed!" << std::endl;

    return 0;
}
