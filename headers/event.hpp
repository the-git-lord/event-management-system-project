#ifndef EVENT
#define EVENT

#include <ctime>
#include <string>
#include <vector>

typedef struct Location {
	std::string building;
	std::string room;
} Location;

class Event {
private:
	std::vector<std::string> participants;
	std::string name;
	unsigned int capacity;
	struct tm *startTime;
	struct tm *endTime;
	Location location;
	double duration;

public:
	Event();
	bool registerParticipant(std::string name);

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
