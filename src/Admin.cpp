#include "Admin.h"
#include "Inventory.h"
#include "Product.h"
#include <iostream>

using namespace std;

Admin::Admin(const string& userID,
             const string& name,
             const string& email,
             const string& passwordHash)
    : User(userID, name, email, passwordHash) {}

void Admin::displayMenu() {
    cout << "\n========================================\n";
    cout << "     ADMIN MENU - Welcome, " << name << "\n";
    cout << "========================================\n";
    cout << "1. Add Product\n";
    cout << "2. Remove Product\n";
    cout << "3. Update Stock\n";
    cout << "4. View Inventory\n";
    cout << "0. Logout\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

string Admin::getRole() const {
    return "Admin";
}

void Admin::addProduct(Inventory& inv) {
    string id;
    string prodName;
    double price = 0.0;
    int qty = 0;

    cout << "Enter Product ID: ";
    cin >> id;
    cout << "Enter Product Name: ";
    cin >> prodName;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> qty;

    inv.addProduct(id, prodName, price, qty);
}

void Admin::removeProduct(Inventory& inv, const string& id) {
    inv.removeProduct(id);
}

void Admin::updateStock(Inventory& inv, const string& id, int qty) {
    inv.updateStock(id, qty);
}

void Admin::viewInventory(Inventory& inv) {
    inv.displayAllProducts();
}