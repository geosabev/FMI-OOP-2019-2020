//62380
#pragma once
#include <iostream>
#include "MyString.h"
using namespace std;

template <class T>
class JSONObject {
public:
	JSONObject();
	JSONObject(MyString _key, T _value);
	JSONObject(const JSONObject<T>& other);
	JSONObject<T>& operator=(const JSONObject<T>& other);

	MyString getKey() const;
	T getValue() const;

	friend ostream& operator<< <>(ostream& out, const JSONObject<T>& _stream);

private:
	MyString key;
	T value;

	void setKey(MyString _key);
	void setValue(T _value);
};

template <class T>
JSONObject<T>::JSONObject() {
	this->setKey("");
	this->setValue(0);
}

template <class T>
JSONObject<T>::JSONObject(MyString _key, T _value) {
	this->setKey(_key);
	this->setValue(_value);
}

template <class T>
JSONObject<T>::JSONObject(const JSONObject<T>& other) {
	this->setKey(other.getKey());
	this->setValue(other.getValue());
}

template <class T>
JSONObject<T>& JSONObject<T>::operator=(const JSONObject<T>& other) {
	if (this == &other)
		return *this;

	this->setKey(other.getKey());
	this->setValue(other.getValue());

	return *this;
}

template <class T>
void JSONObject<T>::setKey(MyString _key) {
	this->key = _key;
}

template <class T>
MyString JSONObject<T>::getKey() const {
	return this->key;
}

template <class T>
void JSONObject<T>::setValue(T _value) {
	this->value = _value;
}

template <class T>
T JSONObject<T>::getValue() const {
	return this->value;
}

template <class T>
ostream& operator<< <>(ostream& out, const JSONObject<T>& _stream) {
	out << "{ " << '"' << _stream.key << '"' << ": " << _stream.value << " }";
	return out;
}