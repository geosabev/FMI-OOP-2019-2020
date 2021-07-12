#pragma once
#include "Peripheral.h"

class Mouse : public Peripheral {
public:
	Mouse() = delete;
	Mouse(string b, string m, double p, unsigned int w,
		string connection, unsigned int _dpi, unsigned int buttons);

	virtual Product* clone() const override;

	virtual void specifications() const override;

	unsigned int getDPI() const;
	unsigned int getButtonsAmount() const;

private:
	unsigned int dpi, buttonsAmount;
};