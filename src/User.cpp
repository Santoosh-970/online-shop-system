#include "User.h"

User::User(const std::string& userID,
           const std::string& name,
           const std::string& email,
           const std::string& passwordHash)
    : userID(userID), name(name), email(email), passwordHash(passwordHash) {}

std::string User::getUserID() const {
    return userID;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPasswordHash() const {
    return passwordHash;
}