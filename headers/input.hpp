#ifndef INPUT
#define INPUT

// class UserInput {

// };

class EventEditInput {
private:
	void setName(Event& event);
	void setCapacity(Event& event);
	void setStartTime(Event& event);
	void setEndTime(Event& event);
	void setLocation(Event& event);
public:
	static void createEvent(std::vector<Event>& EventVector);
	static void chooseEventToEdit(std::vector<Event>& EventVector);
	static void editEvent(Event& event);
};

#endif
