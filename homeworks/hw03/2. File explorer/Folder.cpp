//62380
#include "Folder.h"

Folder::Folder()
	: Content("New Folder"), items() {}

Folder::Folder(string n)
	: Content(n), items() {}

Folder::Folder(const Folder& other)
	: Content(other.name)
{
	unsigned int amount = other.items.size();

	for (unsigned int i = 0; i < amount; i++)
		this->addItem(other.items[i]);
}

Folder& Folder::operator=(const Folder& other) {
	if (this != &other) {
		unsigned int current = this->items.size();
		unsigned int amount = other.items.size();

		for (unsigned int i = 0; i < current; i++) {
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
		}

		for (unsigned int i = 0; i < amount; i++)
			this->addItem(other.items[i]);
	}

	return *this;
}

Folder::~Folder() {
	unsigned int amount = this->items.size();

	for (unsigned int i = 0; i < amount; i++)
		delete this->items[i];
}

void Folder::addItem(Content* item) {
	this->items.push_back(item->clone());
}

void Folder::deleteItem(string n) {
	if (this->items.empty())
		throw out_of_range("Empty!");

	unsigned int amount = this->items.size();

	for (unsigned int i = 0; i < amount; i++) {
		if (this->items[i]->get_name() == n) {
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
			return;
		}
	}

	throw invalid_argument("No such item!");
}

void Folder::search(string input) const {
	unsigned int amount = this->items.size();

	for (unsigned int i = 0; i < amount; i++) {
		string name = this->items[i]->get_name();

		File* current = dynamic_cast<File*>(this->items[i]);

		if (current != nullptr) {
			if (current->get_name() == input) {
				current->info();
				cout << "Location: " << this->get_name() << endl << endl;
			}
		}

		else {
			Folder* current = dynamic_cast<Folder*>(this->items[i]);
			current->search(input);
		}
	}
}

Content* Folder::clone() const {
	return new Folder(*this);
}

void Folder::info() const {
	unsigned int amount = this->items.size();

	cout << "Name: " << this->name << endl;
	cout << "Date created: " << this->date;
	cout << "Items in it: " << amount << endl;
}

unsigned int Folder::amount() const {
	return this->items.size();
}

Content* Folder::item(unsigned int index) const {
	if (this->items.empty())
		throw out_of_range("Empty!");
	else if (this->items.size() <= index)
		throw out_of_range("No such item!");

	return this->items[index];
}