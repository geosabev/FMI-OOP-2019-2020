//62380
#include "IntCounter.h"

IntCounter::IntCounter() {
	this->setValue(nullptr);
	this->setAmount(new unsigned int(0));
}
IntCounter::IntCounter(int* _value) {
	this->setValue(_value);
	this->setAmount(new unsigned int(1));
}
IntCounter::IntCounter(IntCounter& other) {
	this->setValue(other.getValue());
	this->setAmount(other.getAmount());

	(*this->amount)++;
}
IntCounter& IntCounter::operator=(const IntCounter& other) {
	if (this == &other) {
		return *this;
	}

	this->setValue(other.getValue());
	this->setAmount(other.getAmount());

	(*this->amount)++;

	return *this;
}
IntCounter::~IntCounter() {
	if (this->getCount() - 1 == 0) {
		delete this->value;
		delete this->amount;
	}
	else
		(*this->amount)--;
}

void IntCounter::setValue(int* _value) {
	this->value = _value;
}
int* IntCounter::getValue() const {
	return this->value;
}

void IntCounter::setAmount(unsigned int* _amount) {
	this->amount = _amount;
}
unsigned int* IntCounter::getAmount() const {
	return this->amount;
}

unsigned int IntCounter::getCount() const {
	return *(this->getAmount());
}