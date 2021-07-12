#pragma once
#include "Computer.h"

class Laptop : public Computer {
public:
	Laptop() = delete;
	Laptop(string b, string m, double p, unsigned int w, string cpu,
		string gpu, string os, unsigned int storage, unsigned int RAM);

	virtual Product* clone() const override;
};