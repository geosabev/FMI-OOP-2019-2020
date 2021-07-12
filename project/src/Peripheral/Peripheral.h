#pragma once
#include "Product.h"

class Peripheral :public Product {
public:
	Peripheral() = delete;
	Peripheral(string b, string m, double p, unsigned int w, string connection);

	virtual Product* clone() const = 0;

	string getConnectionType() const;

protected:
	string connectionType;
};