//62380
#pragma once
#include <iostream>
#include <math.h>
using namespace std;

double absolute(double _number);

class Point {
public:
	Point();
	Point(double _x, double _y);
	Point& operator=(const Point& other);

	void setX(double _x);
	double getX() const;

	void setY(double _y);
	double getY() const;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	void print() const;
	friend ostream& operator<<(ostream& out, const Point& other);
	friend istream& operator>>(istream& in, Point& other);

private:
	double x, y;
};

double distance(const Point& _p1, const Point& _p2);
bool areOnSameLine(const Point& _p1, const Point& _p2);