#include "AuthManager.h"
#include "Customer.h"
#include "Admin.h"
#include "Exceptions.h"
#include <functional>
#include <iostream>

using namespace std;

AuthManager::AuthManager()
    : currentUser(nullptr) {}

AuthManager::~AuthManager() {
    for (User* user : users) {
        delete user;
    }
    users.clear();
    currentUser = nullptr;
}

bool AuthManager::signUp() {
    string userID;
    string name;
    string email;
    string password;
    string role;

    cout << "Enter User ID: ";
    cin >> userID;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Email: ";
    cin >> email;

    if (findUser(email) != nullptr) {
        cout << "Email already registered.\n";
        return false;
    }

    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role (Customer/Admin): ";
    cin >> role;

    string passwordHash = to_string(hash<string>{}(password));

    User* newUser = nullptr;
    if (role == "Admin" || role == "admin") {
        newUser = new Admin(userID, name, email, passwordHash);
    } else {
        newUser = new Customer(userID, name, email, passwordHash);
    }

    users.push_back(newUser);
    saveUsers();
    return true;
}

User* AuthManager::login() {
    string email;
    string password;

    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    User* found = findUser(email);
    if (found == nullptr) {
        currentUser = nullptr;
        return nullptr;
    }

    string passwordHash = to_string(hash<string>{}(password));
    if (found->getPasswordHash() != passwordHash) {
        currentUser = nullptr;
        return nullptr;
    }

    currentUser = found;
    return currentUser;
}

void AuthManager::logout() {
    currentUser = nullptr;
}

User* AuthManager::findUser(string email) {
    for (User* user : users) {
        if (user != nullptr && user->getEmail() == email) {
            return user;
        }
    }
    return nullptr;
}

void AuthManager::saveUsers() {
    FileManager::saveUsers(users);
}

void AuthManager::loadUsers() {
    for (User* user : users) {
        delete user;
    }
    users.clear();
    currentUser = nullptr;
    users = FileManager::loadUsers();
}