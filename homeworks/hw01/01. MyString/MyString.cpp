//62380
#include "MyString.h"

MyString::MyString() {
	this->str = new char[1];
	this->str[0] = '\0';

	this->len = 0;
}
MyString::MyString(const char* _str) {
	this->len = strlen(_str);
	this->str = new char[this->length() + 1];

	for (unsigned int i = 0; i < (this->length()); i++)
		this->str[i] = _str[i];

	this->str[this->length()] = '\0';
}
MyString::MyString(const char* _str, unsigned int _length) {
	if (_length <= strlen(_str))
		this->len = _length;
	else
		this->len = strlen(_str);

	this->str = new char[this->length() + 1];

	for (unsigned int i = 0; i < (this->length()); i++)
		this->str[i] = _str[i];

	this->str[this->length()] = '\0';
}
MyString::MyString(unsigned int _length, char _symbol) {
	this->len = _length;
	this->str = new char[this->length() + 1];

	for (unsigned int i = 0; i < _length; i++)
		this->str[i] = _symbol;

	this->str[this->length()] = '\0';
}
MyString::MyString(const MyString& other) {
	this->len = other.length();
	this->str = new char[this->length() + 1];
	
	for (unsigned int i = 0; i < (this->length() + 1); i++)
		this->str[i] = other.str[i];

	this->str[this->length()] = '\0';
}
MyString::~MyString() {
	delete[] this->str;
}

MyString& MyString::operator=(const MyString& other) {
	if (this == &other) {
		return *this;
	}

	delete[] this->str;

	this->str = new char[other.length() + 1];

	for (unsigned int i = 0; i < (other.length() + 1); i++)
		this->str[i] = other.str[i];

	this->len = other.length();
	this->str[this->length()] = '\0';

	return *this;
}
MyString& MyString::operator=(const char* other) {
	delete[] this->str;

	this->str = new char[strlen(other) + 1];

	for (unsigned int i = 0; i < (strlen(other) + 1); i++)
		this->str[i] = other[i];

	this->len = strlen(other);
	this->str[this->length()] = '\0';

	return *this;
}

MyString& MyString::operator+=(const MyString& other) {
	if (this->empty()) {
		delete[] this->str;

		this->str = new char[other.length() + 1];

		for (unsigned int i = 0; i < other.length() + 1; i++)
			this->str[i] = other.str[i];

		this->len = other.length();
		this->str[this->length()] = '\0';

		return *this;
	}

	char* temp = new char[this->length() + 1];

	for (unsigned int i = 0; i < this->length() + 1; i++)
		temp[i] = this->str[i];

	delete[] this->str;

	this->str = new char[this->length() + other.length() + 1];

	for (unsigned int i = 0; i < this->length(); i++)
		this->str[i] = temp[i];

	unsigned int currIdx = this->length();

	for (unsigned int i = 0; i < other.length() + 1; i++) {
		this->str[currIdx] = other.str[i];
		currIdx++;
	}

	this->len = this->length() + other.length();

	this->str[this->length()] = '\0';

	delete[] temp;

	return *this;
}
MyString& MyString::operator+=(const char* other) {
	if (this->empty()) {
		delete[] this->str;

		this->str = new char[strlen(other) + 1];

		for (unsigned int i = 0; i < (strlen(other) + 1); i++)
			this->str[i] = other[i];

		this->len = strlen(other);
		this->str[this->length()] = '\0';

		return *this;
	}

	char* temp = new char[this->length() + 1];
	for (unsigned int i = 0; i < this->length() + 1; i++)
		temp[i] = this->str[i];

	delete[] this->str;

	this->str = new char[this->length() + strlen(other) + 1];

	for (unsigned int i = 0; i < (this->length()); i++)
		this->str[i] = temp[i];

	unsigned int currIdx = this->length();

	for (unsigned int i = 0; i < (strlen(other) + 1); i++) {
		this->str[currIdx] = other[i];
		currIdx++;
	}

	this->len = this->length() + strlen(other);
	this->str[this->length()] = '\0';

	delete[] temp;

	return *this;
}

MyString operator+(const MyString& _left, const MyString& _right) {
	if (_left.empty() && _right.empty())
		return MyString();
	else if (_left.empty())
		return _right;
	else if (_right.empty())
		return _left;

	MyString newStr;
	newStr += _left;
	newStr += _right;

	return newStr;
}
MyString operator+(const char* _left, const MyString& _right) {
	MyString newStr = MyString(_left) + _right;
	return newStr;
}
MyString operator+(const MyString& _left, const char* _right) {
	MyString newStr = _left + MyString(_right);
	return newStr;
}

int MyString::compare(const MyString& other) const {
	if (this->length() < other.length())
		return -1;
	else if (this->length() > other.length())
		return 1;
	else {
		unsigned int length = this->length();

		for (unsigned int i = 0; i < length; i++) {
			if (this->str[i] < other.str[i])
				return -1;
			else if (this->str[i] > other.str[i])
				return 1;
			else continue;
		}

		return 0;
	}
}

bool operator==(const MyString& _left, const MyString& _right) {
	if (_left.compare(_right) == 0)
		return 1;
	else return 0;
}
bool operator==(const MyString& _left, const char* _right) {
	return (_left == MyString(_right));
}
bool operator==(const char* _left, const MyString& _right) {
	return (MyString(_left) == _right);
}

bool operator!=(const MyString& _left, const MyString& _right) {
	if (_left.compare(_right) == 0)
		return 0;
	else return 1;
}
bool operator!=(const MyString& _left, const char* _right) {
	return (_left != MyString(_right));
}
bool operator!=(const char* _left, const MyString& _right) {
	return (MyString(_left) != _right);
}

bool operator>(const MyString& _left, const MyString& _right) {
	if(_left.compare(_right) > 0)
		return 1;

	return 0;
}
bool operator>(const MyString& _left, const char* _right) {
	return (_left > MyString(_right));
}
bool operator>(const char* _left, const MyString& _right) {
	return (MyString(_left) > _right);
}

bool operator<(const MyString& _left, const MyString& _right) {
	if (_left.compare(_right) < 0)
		return 1;

	return 0;
}
bool operator<(const MyString& _left, const char* _right) {
	return (_left < MyString(_right));
}
bool operator<(const char* _left, const MyString& _right) {
	return (MyString(_left) < _right);
}

bool operator>=(const MyString& _left, const MyString& _right) {
	if (_left == _right)
		return 1;
	else if (_left > _right)
		return 1;
	
	return 0;
}
bool operator>=(const MyString& _left, const char* _right) {
	return (_left >= MyString(_right));
}
bool operator>=(const char* _left, const MyString& _right) {
	return (MyString(_left) >= _right);
}

bool operator<=(const MyString& _left, const MyString& _right) {
	if (_left == _right)
		return 1;
	else if (_left < _right)
		return 1;

	return 0;
}
bool operator<=(const MyString& _left, const char* _right) {
	return (_left <= MyString(_right));
}
bool operator<=(const char* _left, const MyString& _right) {
	return (MyString(_left) <= _right);
}

char& MyString::operator[](unsigned int _index) const {
	if (this->empty() || _index < 0 || _index >= this->length())
		return this->str[this->length()];

	return this->str[_index];
}

ostream& operator<<(ostream& out, const MyString& _outStr) {
	out << _outStr.str;
	return out;
}
istream& operator>>(istream& in, MyString& _inStr) {
	const int bufferCAP = 1000;
	char buffer[bufferCAP];

	in >> buffer;

	_inStr = MyString(buffer);

	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return in;
}

bool MyString::empty() const {
	if (this->length() == 0 || this->str == nullptr)
		return true;

	return false;
}

void MyString::append(char _symbol) {
	if (this->empty()) {
		delete[] this->str;

		this->str = new char[2];

		this->str[0] = _symbol;
		this->str[1] = '\0';

		this->len = 1;

		return;
	}

	char* temp = new char[this->length() + 1];
	
	for (unsigned int i = 0; i < this->length() + 1; i++)
		temp[i] = this->str[i];

	delete[] this->str;

	this->str = new char[this->length() + 2];

	for (unsigned int i = 0; i < this->length(); i++)
		this->str[i] = temp[i];

	this->str[this->length()] = _symbol;
	this->str[this->length() + 1] = '\0';

	this->len++;

	delete[] temp;
}
void MyString::append(const char* _str) {
	if (this->empty()) {
		delete[] this->str;

		this->str = new char[strlen(_str) + 1];
		strcpy_s(this->str, strlen(_str) + 1, _str);

		this->len = strlen(_str);

		return;
	}

	char* temp = new char[this->length() + 1];

	for (unsigned int i = 0; i < this->length() + 1; i++)
		temp[i] = this->str[i];

	delete[] this->str;

	this->str = new char[this->length() + strlen(_str) + 1];

	for (unsigned int i = 0; i < this->length(); i++)
		this->str[i] = temp[i];

	unsigned int currIdx = 0;
	for (unsigned int i = this->length(); i < this->length() + strlen(_str); i++) {
		this->str[i] = _str[currIdx];
		currIdx++;
	}

	this->len += strlen(_str);

	this->str[this->length()] = '\0';

	delete[] temp;
}
void MyString::popBack() {
	if (this->empty()) {
		cout << "Nothing to remove!" << endl;
		return;
	}

	char* temp = new char[this->length() + 1];

	for (unsigned int i = 0; i < this->length() + 1; i++)
		temp[i] = this->str[i];

	delete[] this->str;

	this->str = new char[this->length()];

	for (unsigned int i = 0; i < this->length() - 1; i++)
		this->str[i] = temp[i];

	this->str[this->length() - 1] = '\0';
	this->len--;

	delete[] temp;
}

const char* MyString::c_str() const {
	return this->str;
}
unsigned int MyString::length() const {
	return this->len;
}

void MyString::print() const {
	cout << this->str << endl;
}