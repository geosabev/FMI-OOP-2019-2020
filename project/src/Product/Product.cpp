#include "Product.h"

Product::Product(string b, string m, double p, unsigned int w)
    : brand(b), model(m), price(p), warranty(w) {}

void Product::info() const {
    cout << this->brand << " " << this->model << endl
        << "Price: " << this->price << " BGN, with "
        << this->warranty << " months warranty" << endl;
}

string Product::getBrand() const {
    return this->brand;
}
string Product::getModel() const {
    return this->model;
}
double Product::getPrice() const {
    return this->price;
}
unsigned int Product::getWarranty() const {
    return this->warranty;
}

string Product::fullName() const {
    return (this->brand + " " + this->model);
}