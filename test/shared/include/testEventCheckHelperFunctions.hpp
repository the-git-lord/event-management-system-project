#ifndef TEST_EVENT_CHECK_HELPER_FUNCTIONS
#define TEST_EVENT_CHECK_HELPER_FUNCTIONS

#include "event.hpp"

bool checkEventEqual(Event& event1, Event& event2);
bool checkNameEqual(Event& event1, Event& event2);
bool checkCapacityEqual(Event& event1, Event& event2);
bool checkStartTimeEqual(Event& event1, Event& event2);
bool checkEndTimeEqual(Event& event1, Event& event2);
bool checkLocationEqual(Event& event1, Event& event2);

bool checkCapacityIsDefault(Event& event);
bool checkTimeEqualDefault(struct tm *time);

#endif
