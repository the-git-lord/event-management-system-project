#ifndef EVENT_COMMUNITY
#define EVENT_COMMUNITY

#include "event.hpp"

class Community : public Event {
public:
	RegisterCode addParticipant(User user);
};

#endif
