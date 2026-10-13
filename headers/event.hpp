#ifndef EVENT
#define EVENT

#include <ctime>
#include <string>

typedef struct Location {
	std::string building;
	std::string room;
} Location;

class Event {
private:
	std::string name;
	unsigned int capacity;
	struct tm *startTime;
	struct tm *endTime;
	Location location;
	double duration;

public:
	Event();
	
	void setName(std::string name);
	void setCapacity(int capacity);
	
	void setStartTime(int minute, int hour, int day, int month, int year);
	void setStartTime(struct tm* time);
	
	void setEndTime(int minute, int hour, int day, int month, int year);
	void setEndTime(struct tm* time);
	
	void setLocation(std::string building, std::string room);
	void setLocation(Location location);

	std::string getName();
	int getCapacity();
	struct tm* getStartTime();
	struct tm* getEndTime();
	Location getLocation();
	double getDurationDays();
};

#endif
