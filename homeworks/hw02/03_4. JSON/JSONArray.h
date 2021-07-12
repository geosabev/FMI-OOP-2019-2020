//62380
#pragma once
#include <iostream>
#include <fstream>
#include "JSONObject.h"
using namespace std;

template <class T>
class JSONArray {
public:
	JSONArray();
	JSONArray(JSONObject<T>* _array, unsigned int _amount);
	JSONArray(const JSONArray<T>& other);
	JSONArray<T>& operator=(const JSONArray<T>& other);
	~JSONArray();

	void add(const JSONObject<T>& _newObject);
	void add(MyString _key, T _value);
	void remove(MyString _key);

	T value(MyString _key) const;

	unsigned int getAmount() const;

	void print() const;

	void writeOutput(const char* _filename) const;

private:
	JSONObject<T>* arr;
	unsigned int amount;

	bool empty() const;
};

template <class T>
JSONArray<T>::JSONArray() {
	this->arr = new JSONObject<T>[0];
	this->amount = 0;
}

template <class T>
JSONArray<T>::JSONArray(JSONObject<T>* _array, unsigned int _amount) {
	this->arr = new JSONObject<T>[_amount];
	this->amount = _amount;

	for (unsigned int i = 0; i < this->amount; i++)
		this->arr[i] = _array[i];
}

template <class T>
JSONArray<T>::JSONArray(const JSONArray<T>& other) {
	this->arr = new JSONObject<T>[other.getAmount()];
	this->amount = other.getAmount();

	for (unsigned int i = 0; i < this->amount; i++)
		this->arr[i] = other.arr[i];
}

template <class T>
JSONArray<T>::~JSONArray() {
	delete[] this->arr;
}

template <class T>
JSONArray<T>& JSONArray<T>::operator=(const JSONArray<T>& other) {
	if (this == &other)
		return *this;

	delete[] this->arr;
	delete amount;

	this->arr = new JSONObject<T>[other.getAmount()];
	this->amount = other.getAmount();

	for (unsigned int i = 0; i < this->amount; i++)
		this->arr[i] = other.arr[i];
}

template <class T>
void JSONArray<T>::add(const JSONObject<T>& _newObject) {
	for (unsigned int i = 0; i < this->amount; i++) {
		if (this->arr[i].getKey() == _newObject.getKey()) {
			cout << "Such object already in list!" << endl;
			return;
		}
	}

	JSONObject<T>* temp = new JSONObject<T>[this->getAmount() + 1];
	
	for (unsigned int i = 0; i < this->amount; i++)
		temp[i] = this->arr[i];

	temp[this->getAmount()] = _newObject;

	delete[] this->arr;
	
	this->amount++;
	this->arr = new JSONObject<T>[this->getAmount()];

	for (unsigned int i = 0; i < this->amount; i++)
		this->arr[i] = temp[i];

	delete[] temp;

	cout << "Object successfully added!" << endl;
}

template <class T>
void JSONArray<T>::add(MyString _key, T _value) {
	this->add(JSONObject<T>(_key, _value));
}

template <class T>
void JSONArray<T>::remove(MyString _key) {
	if (this->empty()) {
		cout << "Empty array!" << endl;
		return;
	}

	bool found = false;
	unsigned int position = 0;

	for (unsigned int i = 0; i < this->amount; i++) {
		if (this->arr[i].getKey() == _key) {
			position = i;
			found = true;
			break;
		}
	}

	if (found == false) {
		cout << "No such key!" << endl;
		return;
	}

	JSONObject<T>* temp = new JSONObject<T>[this->getAmount() - 1];

	for (unsigned int i = 0; i < position; i++)
		temp[i] = this->arr[i];

	for (unsigned int i = position + 1; i < this->amount; i++)
		temp[i - 1] = this->arr[i];

	delete[] this->arr;

	this->amount--;
	this->arr = new JSONObject<T>[this->getAmount()];

	for (unsigned int i = 0; i < this->amount; i++)
		this->arr[i] = temp[i];

	delete[] temp;

	cout << "Object successfully removed!" << endl;
}

template <class T>
T JSONArray<T>::value(MyString _key) const {
	if (this->empty()) {
		cout << "Empty array!" << endl;
		return NULL;
	}

	for (unsigned int i = 0; i < this->amount; i++) {
		if (this->arr[i].getKey() == _key)
			return this->arr[i].getValue();
	}

	cout << "No such key found!" << endl;
	return NULL;
}

template <class T>
unsigned int JSONArray<T>::getAmount() const {
	return this->amount;
}

template <class T>
void JSONArray<T>::print() const {
	if (this->empty()) {
		cout << "Empty array!" << endl;
		return;
	}

	cout << '[' << endl;

	for (unsigned int i = 0; i < this->amount; i++) {
		cout << " ";

		cout << this->arr[i];

		if (i != this->getAmount() - 1)
			cout << ',';

		cout << endl;
	}

	cout << "]" << endl;
}

template <class T>
bool JSONArray<T>::empty() const {
	return (this->getAmount() == 0);
}

template <class T>
void JSONArray<T>::writeOutput(const char* _filename) const {
	fstream log(_filename, ios::out | ios::app);
	unsigned int amount = this->getAmount();

	log << '[' << endl;

	for (unsigned int i = 0; i < amount; i++) {
		log << ' ' << this->arr[i] << endl;
	}

	log << "]" << endl << endl;

	cout << "Output successful!" << endl;

	log.close();
}