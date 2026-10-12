#include <string>

class User {
protected:
	std::string name;
	
public:
	User(std::string name) {
		this->name = name;
	}
};

class Participant: public User {};
class Administrator: public User {};
