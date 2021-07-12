#pragma once
#include "Utility.h"
using namespace std;

class Product {
public:
    Product() = delete;
    Product(string b, string m, double p, unsigned int w);
    virtual ~Product() = default;

    virtual Product* clone() const = 0;
    virtual void specifications() const = 0;

    void info() const;

    string getBrand() const;
    string getModel() const;
    double getPrice() const;
    unsigned int getWarranty() const;

    string fullName() const;

protected:
    string brand, model;
    double price;
    unsigned int warranty;
};