//62380
#pragma once
#include <iostream>
using namespace std;

template <class T>
class Counter {
public:
    Counter();
    Counter(T* _ptr);
    Counter(const Counter<T>& _other);
	Counter<T>& operator=(const Counter<T>& _other);
    ~Counter();

	T getValue() const;
	unsigned int getCount() const;

private:
    T* ptr;
    unsigned int* amount;

	void setPtr(T* _ptr);
	void setAmount(unsigned int* _amount);

	T* getPtr() const;
	unsigned int* getAmount() const;

    void addCount();
    void removeCount();
};

template <class T>
Counter<T>::Counter() {
	this->setPtr(nullptr);
	this->setAmount(new unsigned int(0));
}

template <class T>
Counter<T>::Counter(T* _ptr) {
	this->setPtr(_ptr);
	this->setAmount(new unsigned int(1));
}

template <class T>
Counter<T>::Counter(const Counter<T>& other) {
	this->setPtr(other.getPtr());
	this->setAmount(other.getAmount());

	this->addCount();
}

template <class T>
Counter<T>& Counter<T>::operator=(const Counter<T>& other) {
	if (this->ptr == other.ptr)
		return *this;

	this->removeCount();
	if (this->getCount() == 0) {
		delete this->ptr;
		delete this->amount;
	}

	this->setPtr(other.getPtr());
	this->setAmount(other.getAmount());

	this->addCount();

	return *this;
}

template <class T>
Counter<T>::~Counter() {
	this->removeCount();

	if (this->getCount() == 0) {
		delete this->ptr;
		delete this->amount;
	}
}

template <class T>
void Counter<T>::setPtr(T* _ptr) {
	this->ptr = _ptr;
}

template <class T>
void Counter<T>::setAmount(unsigned int* _amount) {
	this->amount = _amount;
}

template <class T>
T* Counter<T>::getPtr() const {
	return this->ptr;
}

template <class T>
T Counter<T>::getValue() const {
	return *(this->getPtr());
}

template <class T>
unsigned int* Counter<T>::getAmount() const {
	return this->amount;
}

template <class T>
unsigned int Counter<T>::getCount() const {
	return *(this->getAmount());
}

template <class T>
void Counter<T>::addCount() {
	(*this->amount)++;
}

template <class T>
void Counter<T>::removeCount() {
	(*this->amount)--;
}