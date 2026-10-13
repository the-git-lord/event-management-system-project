#ifndef USER_INTERFACE
#define USER_INTERFACE

class UserInterface {
};

class DisplayEvent {
private:
	void name(Event event);
	void capacity(Event event);
	void startTime(Event event);
	void endTime(Event event);
	void location(Event event);
	void durationDays(Event event);	
public:
	static void EventListTable(std::vector<Event> EventVector);
};

#endif
