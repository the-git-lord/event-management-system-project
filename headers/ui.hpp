#ifndef USER_INTERFACE
#define USER_INTERFACE

class Display {
public:
	Display();

	void displayEvent(Event event);
	void eventName(Event event);
	void eventCapacity(Event event);
	void eventStartTime(Event event);
	void eventEndTime(Event event);
	void eventLocation(Event event);
	void eventDurationDays(Event event);
};

#endif
