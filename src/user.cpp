class User {
protected:
	string name;
	
public:
	User(string name) {
		this->name = name;
	}
};

class Participant: public User {};
class Administrator: public User {};
