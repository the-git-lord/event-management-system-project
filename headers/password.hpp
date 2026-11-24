#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <string>

// SHA-256 hash of the input, as 64 lowercase hex characters
std::string sha256(const std::string& input);

// A new random salt: 16 random bytes as 32 hex characters
std::string generateSalt();

// Hash a password together with its salt
// Note: real systems use a deliberatly slow hash (bcrypt, Argon2);
// salted SHA-256 is fine for this project
std::string hashPassword(const std::string& password, const std::string& salt);

// A text file of saved passwords, one user per line: "username salt hash".
// The plain text password is never written to the file.
class PasswordFile {
    private:
    std::string filePath;

    // Looks up a user's line. Returns false if the user is not in the file.
    bool findEntry(std::string username, std::string& salt, std::string& hash) const;

    public:
    PasswordFile(std::string filePath);

    // Adds the user, or replaces their line if they are already saved.
    // Usernames cannot be empty or contain spaces.
    bool save(std::string username, std::string salt, std::string hash);

    bool contains(std::string username) const;

    // True if the password, hashes with the saved salt, matches the saved hash.
    bool verify(std::string username, std::string password) const;

    std::string getFilePath() const;
};

#endif
