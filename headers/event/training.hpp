#ifndef EVENT_TRAINING
#define EVENT_TRAINING

#include "event.hpp"

class Training : public Event {
public:
	RegisterCode addParticipant(User user);
};

#endif
