#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(const string& userID,
                   const string& name,
                   const string& email,
                   const string& passwordHash)
    : User(userID, name, email, passwordHash) {}

void Customer::displayMenu() {
    cout << "\n========================================\n";
    cout << "   CUSTOMER MENU - Welcome, " << name << "\n";
    cout << "========================================\n";
    cout << "1. Browse Products\n";
    cout << "2. Add Product to Cart\n";
    cout << "3. Remove Product from Cart\n";
    cout << "4. View Cart\n";
    cout << "5. Place Order\n";
    cout << "0. Logout\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

std::string Customer::getRole() const {
    return "Customer";
}

void Customer::browseProducts(Inventory& inv) {
    inv.displayAllProducts();
}

void Customer::addToCart(const Product& prod, int qty) {
    cart.addItem(prod, qty);
}

void Customer::removeFromCart(const string& prodID) {
    cart.removeItem(prodID);
}

Order Customer::placeOrder(Inventory& inv) {
    // Deduct purchased quantities from inventory and build the Order
    Order newOrder = cart.checkout(userID, inv);
    return newOrder;
}

ShoppingCart& Customer::getCart() {
    return cart;
}