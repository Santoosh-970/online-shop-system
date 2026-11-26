#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H

#include "User.h"
#include "FileManager.h"
#include <string>
#include <vector>

using namespace std;

class AuthManager {
private:
    vector<User*> users;
    User* currentUser;

public:
    AuthManager();
    ~AuthManager();

    bool signUp();
    User* login();
    void logout();
    User* findUser(string email);
    void saveUsers();
    void loadUsers();
};

#endif // AUTH_MANAGER_H