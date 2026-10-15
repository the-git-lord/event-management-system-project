#ifndef USER_HPP
#define USER_HPP

#include <string>

enum class Role {
    PARTICIPANT,
    ADMINISTRATOR
};

class User {
protected:
    std::string name;
    std::string username;
    std::string password;
    Role role;
    bool loggedIn;


public:
    User(std::string name, std::string username, std::string password, Role role);
    virtual ~User() = default;

    bool login(std::string username, std::string password);
    void logout();

    std::string getName() const;
    std::string getUsername() const;
    Role getRole() const;
    bool isLoggedIn() const;

    // True if the user is an administrator, false otherwise
    bool hasAdminPrivileges() const;
};

class Participant : public User {
public:
    Participant(std::string name, std::string username, std::string password);
};

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
