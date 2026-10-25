#ifndef EVENT
#define EVENT

#include <ctime>
#include <string>
#include <vector>
#include <forward_list>

#include "user.hpp"
#include "waitlist.hpp"

enum class RegisterCode {
	ADDED_TO_EVENT,
	ADDED_TO_WAITLIST
};

typedef struct Location {
	std::string building;
	std::string room;
} Location;

class Event : public Waitlist {
private:
	std::forward_list<User> participants;
	unsigned int enrolled;
	
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
	virtual ~Event() = default;
	
	RegisterCode addParticipant(User name);
	
	void setName(std::string name);
	void setCapacity(int capacity);
	void setStartTime(int minute, int hour, int day, int month, int year);
	void setStartTime(struct tm* time);
	void setEndTime(int minute, int hour, int day, int month, int year);
	void setEndTime(struct tm* time);
	void setLocation(std::string building, std::string room);
	void setLocation(Location location);

	std::forward_list<User> getParticipants() const;
	unsigned int getEnrolledSize();
	std::string getName();
	unsigned int getCapacity();
	struct tm* getStartTime();
	struct tm* getEndTime();
	Location getLocation();
	double getDurationDays();
};

#endif
