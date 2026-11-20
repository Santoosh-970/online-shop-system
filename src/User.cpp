#include "User.h"
#include <string>

using namespace std;

User::User(const string& userID,
           const string& name,
           const string& email,
           const string& passwordHash)
    : userID(userID), name(name), email(email), passwordHash(passwordHash) {}

string User::getUserID() const {
    return userID;
}

string User::getName() const {
    return name;
}

string User::getEmail() const {
    return email;
}

string User::getPasswordHash() const {
    return passwordHash;
}