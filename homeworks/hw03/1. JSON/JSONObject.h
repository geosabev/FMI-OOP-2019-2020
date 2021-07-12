//62380
#pragma once
#include "JSONBase.h"

template <class T>
class JSONObject : public JSONBase {
public:
	JSONObject(string k, T v);

	string get_key() const;
	T get_value() const;

	virtual JSONBase* clone() const override;
	virtual void print() const override;

private:
	string key;
	T value;
};

template <class T>
JSONObject<T>::JSONObject(string k, T v)
	: key(k), value(v) {}

template <class T>
string JSONObject<T>::get_key() const {
	return this->key;
}

template <class T>
T JSONObject<T>::get_value() const {
	return this->value;
}

template <class T>
JSONBase* JSONObject<T>::clone() const {
	return new JSONObject<T>(*this);
}

template<class T>
void JSONObject<T>::print() const {
	cout << "{ " << '"' << this->key << '"' << ": " << this->value << " }";
}