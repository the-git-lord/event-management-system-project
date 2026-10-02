class Event {
private:
	typedef struct Date {
		int year;
		string month;
		int day;
	} Date;

	typedef struct Time {
		int hour;
		int minute;
	} Time;
	
	const string months[] = {"January", "February", "March", "April", "May",
							 "June", "July", "August", "September", "October", "November", "December"};

private:
	string name;
	Date date;
	Time time;
	string location;
	
public:
	Event(string eventName, Date eventDate, Time eventTime, string eventLocation) {
		setName(eventName);
		setDate(eventDate);
		setTime(eventTime);
		setLocation(eventLocation);
	}

	void setName(string eventName) {
		name = eventName;
	}
	
	void setDate(Date eventDate) {
		date = eventDate;
	}

	void setTime(Time eventTime) {
		time = eventTime;
	}

	void setLocation(string eventLocation) {
		location = eventLocation;
	}
	
	string getName() { return name; }
	string getDate() { return date; }
	string getTime() { return time; }
	string getLocation() { return location; }
	
	string getDuration() {
		
	}
}
