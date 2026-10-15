#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
protected:
    std::string name;

public:
    User(std::string name);

    std::string getName() const;
};

class Participant : public User {
public:
    Participant(std::string name);
};

class Administrator : public User {
public:
    Administrator(std::string name);
};

#endif 