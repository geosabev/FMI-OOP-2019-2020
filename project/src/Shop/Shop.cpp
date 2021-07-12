#include "Shop.h"

Shop::Shop()
    : name("Shop"), products(), accounts() {}
Shop::Shop(string n)
    : name(n), products(), accounts() {}
Shop::Shop(vector<Product*> list)
    : name("Shop"), accounts()
{
    unsigned int amount = list.size();
    for (unsigned int i = 0; i < amount; i++)
        this->addProduct(list[i]);
}
Shop::Shop(string n, vector<Product*> list)
    : name(n), accounts()
{
    unsigned int amount = list.size();
    for (unsigned int i = 0; i < amount; i++)
        this->addProduct(list[i]);
}
Shop::Shop(const Shop& other) {
    this->name = other.name;
    this->accounts = other.accounts;

    unsigned int amount = other.productsAmount();
    for (unsigned int i = 0; i < amount; i++)
        this->addProduct(other.products[i]);
}
Shop& Shop::operator=(const Shop& other) {
    if (this != &other) {
        this->name = other.name;
        this->accounts = other.accounts;

        unsigned int amount = other.productsAmount();
        for (unsigned int i = 0; i < amount; i++)
            this->addProduct(other.products[i]);
    }

    return *this;
}
Shop::~Shop() {
    unsigned int amount = this->productsAmount();
    for (int i = 0; i < amount; i++)
        delete this->products[i];
}

Product* Shop::getProduct(unsigned int index) const {
    return this->products[index];
}
const Account& Shop::getAccount(unsigned int index) const {
    return this->accounts[index];
}

unsigned int Shop::productsAmount() const {
    return this->products.size();
}
unsigned int Shop::accountsAmount() const {
    return this->accounts.size();
}

void Shop::addProduct(Product* p) {
    try {
        if (canAdd(p))
            this->products.push_back(p->clone());
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
}
void Shop::deleteProduct(unsigned int index) {
    unsigned int ammount = this->productsAmount();

    if (ammount <= index)
        throw out_of_range("No such product!");

    else {
        delete this->products[index];
        this->products.erase(products.begin() + index);
    }
}

void Shop::registerAccount(const Account& a) {
    try {
        if (canRegister(a))
            this->accounts.push_back(a);
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
}
void Shop::registerAccount(string u, string p, unsigned int age, string email, string address) {
    Account a(u, p, age, email, address);
    this->registerAccount(a);
}
void Shop::deleteAccount(unsigned int index) {
    unsigned int amount = this->accountsAmount();

    if (amount <= index)
        throw out_of_range("No such account!");

    else
        this->accounts.erase(accounts.begin() + index);
}

void Shop::productInfo(unsigned int index) const {
    unsigned int amount = this->productsAmount();

    if (amount <= index)
        throw out_of_range("No such product!");

    else {
        Product* p = this->getProduct(index);
        p->info();
        p->specifications();
    }
}
void Shop::productsList() const {
    headline("PRODUCTS");

    unsigned int amount = this->productsAmount();

    if (amount == 0)
        cout << "No products available!" << endl;
    else {
        for (int i = 0; i < amount; i++) {
            cout << i+1 << ". ";
            products[i]->info();
            products[i]->specifications();
            cout << endl;
        }
    }

    bottomLine("PRODUCTS");
}
void Shop::search(string input) const {
    unsigned int resultCount = 0;

    cout << "Searching for " << '"' << input << '"' << endl;

    headline("RESULTS");

    unsigned int amount = this->productsAmount();

    for (int i = 0; i < amount; i++) {
        string current = this->products[i]->fullName();

        if (contains(current, input)) {
            cout << i << ". ";
            this->products[i]->info();

            resultCount++;

            cout << endl;
        }
    }

    cout << resultCount;

    if (resultCount == 1)
        cout << " result ";
    else cout << " results ";

    cout << "found" << endl;

    bottomLine("RESULTS");
}

void Shop::accountInfo(unsigned int index) const {
    unsigned int amount = this->accountsAmount();

    if (amount <= index)
        throw out_of_range("No such account!");
    else
        this->accounts[index].info();
}
void Shop::accountsList() const {
    headline("ACCOUNTS");

    unsigned int amount = this->accountsAmount();

    if (amount == 0)
        cout << "No accounts registered!" << endl;
    else {
        for (int i = 0; i < amount; i++) {
            cout << i+1 << ". ";
            accounts[i].info();
        }
    }

    bottomLine("ACCOUNTS");
}

void Shop::addToCart(unsigned int aIndex, unsigned int pIndex) {
    unsigned int productsAmount = this->productsAmount();
    unsigned int accountsAmount = this->accountsAmount();

    if (accountsAmount <= aIndex)
        throw out_of_range("No such account!");
    else if (productsAmount <= pIndex)
        throw out_of_range("No such product!");
    else
        this->accounts[aIndex].addToCart(this->getProduct(pIndex));
}
void Shop::removeFromCart(unsigned int aIndex, unsigned int pIndex) {
    unsigned int productsAmount = this->productsAmount();
    unsigned int accountsAmount = this->accountsAmount();

    if (accountsAmount <= aIndex)
        throw out_of_range("No such account!");
    else
        this->accounts[aIndex].removeFromCart(pIndex);
}
void Shop::printCart(unsigned int index) const {
    unsigned int accountsAmount = this->accountsAmount();

    if (accountsAmount <= index)
        throw out_of_range("No such account!");
    else
        this->accounts[index].inCart();
}
void Shop::buyCart(unsigned int index) {
    unsigned int accountsAmount = this->accountsAmount();

    if (accountsAmount <= index)
        throw out_of_range("No such account!");
    else
        this->accounts[index].buyCart();
}

bool Shop::canAdd(Product* p) const {
    unsigned int amount = this->productsAmount();
    
    string brand = p->getBrand();
    string model = p->getModel();
    string name = p->fullName();
    double price = p->getPrice();

    if (brand.empty() || model.empty())
        throw invalid_argument("Not enough information!");

    else if (price == 0)
        throw invalid_argument("Product should have a price!");

    else {
        for (unsigned int i = 0; i < amount; i++) {
            string currentName = this->products[i]->fullName();

            if (same(currentName, name))
                throw invalid_argument("Such product already exists!");
        }
    }

    return 1;
}
bool Shop::canRegister(const Account& a) const {
    unsigned int amount = this->accountsAmount();
    string name = a.getUsername();
    string email = a.getEmail();
    unsigned int age = a.getAge();

    for (unsigned int i = 0; i < amount; i++) {
        if (same(this->accounts[i].getUsername(), name))
            throw invalid_argument("Username already taken!");

        else if (name.empty() || email.empty())
            throw invalid_argument("Invalid input!");

        else if (same(this->accounts[i].getEmail(), email))
            throw invalid_argument("Email already taken!");

        else if (age < 18)
            throw invalid_argument("You must be at least 18 years old!");
    }

    return 1;
}