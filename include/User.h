#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string userID;
    std::string name;
    std::string email;
    std::string passwordHash;

public:
    User(const std::string& userID,
         const std::string& name,
         const std::string& email,
         const std::string& passwordHash);

    virtual ~User() = default;

    // Pure virtual method enforcing runtime polymorphism in Customer and Admin
    virtual void displayMenu() = 0;

    // Role identifier ("Customer" or "Admin")
    virtual std::string getRole() const = 0;

    // Getters
    std::string getUserID() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPasswordHash() const;
};

#endif // USER_H