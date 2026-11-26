#include "Exceptions.h"

using namespace std;

ShopException::ShopException(const string& msg)
    : message(msg) {}

const char* ShopException::what() const noexcept {
    return message.c_str();
}

AuthenticationException::AuthenticationException(const string& msg)
    : ShopException("Authentication Error: " + msg) {}

ProductNotFoundException::ProductNotFoundException(const string& msg)
    : ShopException("Product Not Found: " + msg) {}

InsufficientStockException::InsufficientStockException(const string& msg)
    : ShopException("Insufficient Stock: " + msg) {}