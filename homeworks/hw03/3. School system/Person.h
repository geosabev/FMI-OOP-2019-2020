#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
	Person(string n);

	string get_name() const;

private:
	string name;
};