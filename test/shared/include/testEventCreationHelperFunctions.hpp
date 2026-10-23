#ifndef TEST_EVENT_CREATION_HELPER_FUNCTIONS
#define TEST_EVENT_CREATION_HELPER_FUNCTIONS

#include "event.hpp"

Event createEventOutOfBounds();
Event createValidEvent();
Event createValidEventCopy(Event& event);
Event createEventOneCapacity();

#endif
