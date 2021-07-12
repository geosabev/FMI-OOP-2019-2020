#pragma once
#include "Peripheral.h"

class Keyboard : public Peripheral {
public:
	Keyboard() = default;
	Keyboard(string b, string m, double p, unsigned int w,
		string connection, bool num, bool cyr);

	virtual Product* clone() const override;

	virtual void specifications() const override;

	bool hasNumpad() const;
	bool hasCyrillic() const;

private:
	bool numpad, cyrillic;
};