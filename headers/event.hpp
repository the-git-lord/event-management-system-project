#ifndef EVENT
#define EVENT

#include <ctime>
#include <string>
#include <vector>

typedef struct Location {
	std::string building;
	std::string room;
} Location;

class User;
class Event { 
	friend class User;
private:
	std::vector<std::string> participants;
	std::string name;
	unsigned int capacity;
	struct tm *startTime;
	struct tm *endTime;
	Location location;
	double duration;

private:
	void setMinute(struct tm *time, int minute);
	void setHour(struct tm *time, int hour);
	void setDay(struct tm *time, int day);
	void setMonth(struct tm *time, int month);
	void setYear(struct tm *time, int year);

public:
	Event();

	std::vector<std::string> getParticipants() const;
	
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
