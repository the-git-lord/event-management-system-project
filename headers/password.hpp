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

#endif