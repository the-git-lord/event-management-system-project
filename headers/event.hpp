#ifndef EVENT
#define EVENT

#include <string>

class Event {
private:
	typedef struct Date {
		int year;
		int month;
		int day;
	} Date;

	typedef struct Time {
		int hour;
		int minute;
	} Time;

	typedef struct Location {
		std::string building;
		std::string room;
	} Location;

private:
	std::string name;
	Date date;
	Time time;
	Location location;

public:
	Event();
	
	void setName(std::string name);
	void setDate(int year, int month, int day);
	void setTime(int hour, int minute);
	void setLocation(std::string building, std::string room);

	std::string getName();
	Date getDate();
	Time getTime();
	Location getLocation();
};

#endif
