#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class ShopException : public exception {
protected:
    string message;

public:
    explicit ShopException(const string& msg);
    const char* what() const noexcept override;
};

class AuthenticationException : public ShopException {
public:
    explicit AuthenticationException(const string& msg);
};

class ProductNotFoundException : public ShopException {
public:
    explicit ProductNotFoundException(const string& msg);
};

class InsufficientStockException : public ShopException {
public:
    explicit InsufficientStockException(const string& msg);
};

#endif // EXCEPTIONS_H