#include "Keyboard.h"

Keyboard::Keyboard(string b, string m, double p, unsigned int w,
	string connection, bool num, bool cyr)
	: Peripheral(b, m, p, w, connection), numpad(num), cyrillic(cyr) {}

Product* Keyboard::clone() const {
	return new Keyboard(*this);
}

void Keyboard::specifications() const {
	cout << this->connectionType << " Keyboard ";

	if (this->hasNumpad())
		cout << "with";
	else cout << "without";

	cout << " numpad and ";

	if (this->hasCyrillic())
		cout << "with";
	else cout << "without";

	cout << " cyrillic.";
}

bool Keyboard::hasNumpad() const {
	return this->numpad;
}
bool Keyboard::hasCyrillic() const {
	return this->cyrillic;
}

