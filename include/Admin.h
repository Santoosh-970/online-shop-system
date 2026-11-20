#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>

class Inventory;
class Product;

class Admin : public User {
public:
    Admin(const std::string& userID,
          const std::string& name,
          const std::string& email,
          const std::string& passwordHash);

    ~Admin() override = default;

    // Overridden methods from User
    void displayMenu() override;
    std::string getRole() const override;

    // Admin operations matching UML
    void addProduct(Inventory& inv);
    void removeProduct(Inventory& inv, const std::string& id);
    void updateStock(Inventory& inv, const std::string& id, int qty);
    void viewInventory(Inventory& inv);
};

#endif // ADMIN_H