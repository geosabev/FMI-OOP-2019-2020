#include "Peripheral.h"

Peripheral::Peripheral(string b, string m, double p, unsigned int w, string connection)
	: Product(b, m, p, w), connectionType(connection) {}

string Peripheral::getConnectionType() const {
	return this->connectionType;
}