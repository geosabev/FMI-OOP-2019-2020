#pragma once
#include "Product.h"

class Smartphone : public Product {
public:
	Smartphone() = delete;
	Smartphone(string b, string m, double p, unsigned int w, string OS, double d);

	virtual Product* clone() const override;

	virtual void specifications() const override;

	string getOS() const;
	double getDisplay() const;

private:
	string OS;
	double display;
};