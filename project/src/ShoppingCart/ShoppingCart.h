#pragma once
#include "Product.h"

class ShoppingCart {
public:
    ShoppingCart();

    void buy();
    void add(Product* p);
    void remove(unsigned int index);
    void clear();

    void print() const;
    double total() const;

private:
    vector<Product*> items;
    unsigned int CAP = 10;
    double sum;

    unsigned int amount() const;
    bool empty() const;
    bool full() const;
};