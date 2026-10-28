#ifndef EVENT_WORKSHOP
#define EVENT_WORKSHOP

#include "event.hpp"

class Workshop : public Event {
public:
	RegisterCode addParticipant(User user);
}

#endif
