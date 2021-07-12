#include "Mouse.h"

Mouse::Mouse(string b, string m, double p, unsigned int w,
	string connection, unsigned int _dpi, unsigned int buttons)
	: Peripheral(b, m, p, w, connection), dpi(_dpi), buttonsAmount(buttons) {}

Product* Mouse::clone() const {
	return new Mouse(*this);
}

void Mouse::specifications() const {
	cout << this->connectionType << " Mouse with " 
		<< this->dpi << " DPI, and "
		<< this->buttonsAmount << " buttons" << endl;
}

unsigned int Mouse::getDPI() const {
	return this->dpi;
}
unsigned int Mouse::getButtonsAmount() const {
	return this->buttonsAmount;
}