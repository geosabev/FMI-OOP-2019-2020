#pragma once
#include "ShoppingCart.h"

class Account {
public:
    Account() = delete;
    Account(string un, string pw, unsigned int age, string email, string addr);

    void buyCart();
    void addToCart(Product* p);
    void removeFromCart(unsigned int index);
    void inCart() const;

    void info() const;

    string getUsername() const;
    string getPassword() const;
    unsigned int getAge() const;
    string getEmail() const;
    string getAddress() const;

private:
    string username, password, email, address;
    unsigned int age;
    ShoppingCart cart;
};