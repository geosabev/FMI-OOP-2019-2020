#pragma once
#include "Desktop.h"
#include "Laptop.h"
#include "Smartphone.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Account.h"
using namespace std;

class Shop {
public:
    Shop();
    Shop(string n);
    Shop(vector<Product*> list);
    Shop(string n, vector<Product*> list);
    Shop(const Shop& other);
    Shop& operator=(const Shop& other);
    ~Shop();

    Product* getProduct(unsigned int index) const;
    const Account& getAccount(unsigned int index) const;

    unsigned int productsAmount() const;
    unsigned int accountsAmount() const;

    void addProduct(Product* p);
    void deleteProduct(unsigned int index);
    void productInfo(unsigned int index) const;

    void registerAccount(string u, string p, unsigned int age, string email, string address);
    void registerAccount(const Account& a);
    void deleteAccount(unsigned int index);
    void accountInfo(unsigned int index) const;

    void productsList() const;
    void accountsList() const;

    void search(string input) const;

    void addToCart(unsigned int aIndex, unsigned int pIndex);
    void removeFromCart(unsigned int aIndex, unsigned int pIndex);
    void printCart(unsigned int index) const;
    void buyCart(unsigned int index);

private:
    string name;
    vector<Account> accounts;
    vector<Product*> products;

    bool canAdd(Product* p) const;
    bool canRegister(const Account& a) const;
};