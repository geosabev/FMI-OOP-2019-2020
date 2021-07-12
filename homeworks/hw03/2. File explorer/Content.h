//62380
#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

class Content {
public:
	Content(string n);
	virtual ~Content() = default;

	string get_name() const;
	string get_date() const;

	virtual Content* clone() const = 0;
	virtual void info() const = 0;
	
	bool operator==(const Content& other) const;

protected:
	string name, date;

	void set_date();
	void set_name(string n);
};