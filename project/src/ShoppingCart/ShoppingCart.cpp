#include <iostream>
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    this->items.clear();
    this->sum = 0;
}

void ShoppingCart::buy() {
    headline("ORDER");

    if (this->empty())
        cout << "Empty shopping cart!" << endl;
    else {
        this->clear();
        cout << "Order successful!" << endl;
    }

    bottomLine("ORDER");
}
void ShoppingCart::add(Product* p) {
    if (this->full())
        cout << "Full cart! You cannot add more than " << this->CAP << " items!" << endl;
    else {
        unsigned int amount = this->amount();

        string name = p->fullName();

        for (unsigned int i = 0; i < amount; i++) {
            string current = this->items[i]->fullName();
            if (current == name) {
                cout << name << " already in shopping cart!" << endl;
                return;
            }
        }

        this->items.push_back(p);
        this->sum = this->total();
    }
}
void ShoppingCart::remove(unsigned int index) {
    unsigned int amount = this->amount();

    if (this->empty())
        cout << "Empty shopping cart!" << endl;
    else if (index >= amount)
        throw out_of_range("No such product!");
    else {
        string name = this->items[index]->fullName();

        this->sum -= this->items[index]->getPrice();
        this->items.erase(items.begin() + index);
    }

}
void ShoppingCart::clear() {
    this->items.clear();
    this->sum = 0;
}

void ShoppingCart::print() const {
    unsigned int currentAmount = this->amount();

    headline("SHOPPING CART");

    if (this->empty())
        cout << "Empty shopping cart!" << endl;
    else {
        for (unsigned int i = 0; i < currentAmount; i++) {
            cout << i + 1 << ". ";
            this->items[i]->info();

            if (i < (currentAmount - 1))
                cout << endl;
        }
    }

    cout << endl << "Total: " << this->sum << " BGN" << endl;
    bottomLine("SHOPPING CART");
}
double ShoppingCart::total() const {
    unsigned int amount = this->amount();
    double result = 0;

    for (unsigned int i = 0; i < amount; i++)
        result += this->items[i]->getPrice();

    return result;
}

unsigned int ShoppingCart::amount() const {
    return this->items.size();
}
bool ShoppingCart::empty() const {
    return (this->amount() == 0);
}
bool ShoppingCart::full() const {
    return (this->amount() == CAP);
}