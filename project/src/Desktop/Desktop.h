#pragma once
#include "Computer.h"

class Desktop : public Computer {
public:
	Desktop() = delete;
	Desktop(string b, string m, double p, unsigned int w, string cpu,
		string gpu, string os, unsigned int storage, unsigned int RAM);

	virtual Product* clone() const override;
};