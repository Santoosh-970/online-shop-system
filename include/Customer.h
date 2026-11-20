#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "ShoppingCart.h"
#include "Inventory.h"
#include "Product.h"
#include "Order.h"
#include <string>

class Customer : public User {
private:
    ShoppingCart cart;

public:
    Customer(const std::string& userID,
             const std::string& name,
             const std::string& email,
             const std::string& passwordHash);

    ~Customer() override = default;

    // Overridden methods from User
    void displayMenu() override;
    std::string getRole() const override;

    // Customer operations matching UML
    void browseProducts(Inventory& inv);
    void addToCart(const Product& prod, int qty);
    void removeFromCart(const std::string& prodID);
    Order placeOrder(Inventory& inv);

    // helper to access the customer's cart directly
    ShoppingCart& getCart();
};

#endif // CUSTOMER_H