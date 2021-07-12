#include "Account.h"

Account::Account(string un, string pw, unsigned int a, string mail, string addr)
    : username(un), password(pw), age(a), email(mail), address(addr), cart() {}

void Account::buyCart() {
    this->cart.buy();
}
void Account::addToCart(Product* p) {
    this->cart.add(p);
}
void Account::removeFromCart(unsigned int index) {
    this->cart.remove(index);
}
void Account::inCart() const {
    this->cart.print();
}

void Account::info() const {
    cout << "Username: " << this->username << endl
        << this->age << " years old" << endl;
}

string Account::getUsername() const {
    return this->username;
}
string Account::getPassword() const {
    return this->password;
}
unsigned int Account::getAge() const {
    return this->age;
}
string Account::getEmail() const {
    return this->email;
}
string Account::getAddress() const {
    return this->address;
}