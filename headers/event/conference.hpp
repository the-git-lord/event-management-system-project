#ifndef EVENT_CONFERENCE
#define EVENT_CONFERENCE

#include "event.hpp"

class Conference : public Event {
public:
	RegisterCode addParticipant(User user);
}

#endif
