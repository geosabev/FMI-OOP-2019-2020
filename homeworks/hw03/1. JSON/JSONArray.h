//62380
#pragma once
#include "JSONObject.h"

template <class T>
class JSONArray : public JSONBase {
public:
	JSONArray();
	JSONArray(const JSONArray& other);
	JSONArray& operator=(const JSONArray& other);
	~JSONArray();

	JSONBase* operator[] (unsigned int index) const;

	template <class J>
	void add(const J& object);
	void add(JSONBase* object);
	void add(string k, T v);
	
	void remove(string k);

	T get_value(string k) const;

	virtual JSONBase* clone() const override;
	virtual void print() const override;

private:
	vector<JSONBase*> data;

	bool exists(string k) const;
};

template <class T>
JSONArray<T>::JSONArray()
	: data() {}

template<class T>
JSONArray<T>::JSONArray(const JSONArray& other) {
	unsigned int amount = other.data.size();

	for (unsigned int i = 0; i < amount; i++)
		this->add(other.data[i]);
}

template<class T>
JSONArray<T>& JSONArray<T>::operator=(const JSONArray& other) {
	if (this != &other) {
		unsigned int current = this->data.size();
		unsigned int amount = other.data.size();

		for (unsigned int i = 0; i < current; i++) {
			delete this->data[i];
			this->data.erase(this->data.begin() + i);
		}

		for (unsigned int i = 0; i < amount; i++)
			this->add(other.data[i]);
	}

	return *this;
}

template<class T>
JSONArray<T>::~JSONArray() {
	unsigned int amount = this->data.size();

	for (unsigned int i = 0; i < amount; i++)
		delete this->data[i];
}

template<class T>
JSONBase* JSONArray<T>::operator[](unsigned int index) const {
	if (this->data.empty())
		throw out_of_range("Empty!");
	else if (this->data.size() <= index)
		throw out_of_range("No such key!");
	return this->data[index];
}

template <class T>
JSONBase* JSONArray<T>::clone() const {
	return new JSONArray<T>(*this);
}

template<class T>
void JSONArray<T>::add(JSONBase* object) {
	this->data.push_back(object->clone());
}

template <class T>
template <class J>
void JSONArray<T>::add(const J& object) {
	JSONBase* obj = new J(object);
	this->add(obj);
	delete obj;
}

template <class T>
void JSONArray<T>::add(string k, T v) {
	this->add(JSONObject<T>(k, v));
}

template <class T>
void JSONArray<T>::remove(string k) {
	if (this->data.empty())
		throw out_of_range("Empty!");
	else if (this->exists(k) == false)
		throw invalid_argument("No such key!");
	else {
		unsigned int amount = this->data.size();

		for (unsigned int i = 0; i < amount; i++) {
			JSONObject<T>* current = dynamic_cast<JSONObject<T>*>(data[i]);

			if (current != nullptr) {
				if (current->get_key() == k) {
					delete this->data[i];
					this->data.erase(this->data.begin() + i);

					return;
				}
			}

			else {
				JSONArray<T>* current = dynamic_cast<JSONArray<T>*>(data[i]);

				if (current->exists(k))
					current->remove(k);
			}
		}
	}
}

template <class T>
T JSONArray<T>::get_value(string k) const {
	unsigned int amount = this->data.size();

	for (unsigned int i = 0; i < amount; i++) {
		JSONObject<T>* current = dynamic_cast<JSONObject<T>*>(this->data[i]);

		if (current != nullptr) {
			if (current->get_key() == k)
				return current->get_value();
		}

		else {
			JSONArray<T>* current = dynamic_cast<JSONArray<T>*>(this->data[i]);

			if (current->exists(k))
				return current->get_value(k);
		}
	}

	throw invalid_argument("No such key!");
}

template <class T>
bool JSONArray<T>::exists(string k) const {
	unsigned int amount = this->data.size();

	for (unsigned int i = 0; i < amount; i++) {
		JSONObject<T>* current = dynamic_cast<JSONObject<T>*>(data[i]);

		if (current != nullptr) {
			if (current->get_key() == k)
				return 1;
		}

		else {
			JSONArray<T>* current = dynamic_cast<JSONArray<T>*>(data[i]);

			if (current->exists(k))
				return 1;
		}
	}

	return 0;
}

template <class T>
void JSONArray<T>::print() const {
	if (this->data.empty())
		throw out_of_range("Empty!");
	else {
		unsigned int amount = this->data.size();

		cout << '[' << endl;

		for (unsigned int i = 0; i < amount; i++) {
			cout << " ";

			this->data[i]->print();

			if (i != amount - 1)
				cout << ',';

			cout << endl;
		}

		cout << "]";
	}
}