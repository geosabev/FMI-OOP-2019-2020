//62380
#pragma once
#include <iostream>
using namespace std;

class MyString {
public:
	MyString();
	MyString(const char* _str);
	MyString(const char* _str, unsigned int _length);
	MyString(unsigned int _length, char _symbol);
	MyString(const MyString& other);
	~MyString();

	MyString& operator=(const MyString& other);
	MyString& operator=(const char* other);

	MyString& operator+=(const MyString& other);
	MyString& operator+=(const char* other);

	friend MyString operator+(const MyString& _left, const MyString& _right);
	friend MyString operator+(const char* _left, const MyString& _right);
	friend MyString operator+(const MyString& _left, const char* _right);

	int compare(const MyString& other) const;

	friend bool operator==(const MyString& _left, const MyString& _right);
	friend bool operator==(const MyString& _left, const char* _right);
	friend bool operator==(const char* _left, const MyString& _right);

	friend bool operator!=(const MyString& _left, const MyString& _right);
	friend bool operator!=(const MyString& _left, const char* _right);
	friend bool operator!=(const char* _left, const MyString& _right);

	friend bool operator>(const MyString& _left, const MyString& _right);
	friend bool operator>(const MyString& _left, const char* _right);
	friend bool operator>(const char* _left, const MyString& _right);

	friend bool operator<(const MyString& _left, const MyString& _right);
	friend bool operator<(const MyString& _left, const char* _right);
	friend bool operator<(const char* _left, const MyString& _right);

	friend bool operator>=(const MyString& _left, const MyString& _right);
	friend bool operator>=(const MyString& _left, const char* _right);
	friend bool operator>=(const char* _left, const MyString& _right);

	friend bool operator<=(const MyString& _left, const MyString& _right);
	friend bool operator<=(const MyString& _left, const char* _right);
	friend bool operator<=(const char* _left, const MyString& _right);

	char& operator[](unsigned int _index) const;

	friend ostream& operator<<(ostream& out, const MyString& _outStr);
	friend istream& operator>>(istream& in, MyString& _inStr);

	bool empty() const;

	void append(char _symbol);
	void append(const char* _str);
	void popBack();

	const char* c_str() const;
	unsigned int length() const;

private:
	char* str;
	unsigned int len;
};
