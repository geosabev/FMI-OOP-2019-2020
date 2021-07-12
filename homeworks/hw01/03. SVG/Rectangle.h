//62380
#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Rectangle {
public:
	Rectangle();
	Rectangle(const Point& _p1, const Point& _p3);
	Rectangle& operator=(const Rectangle& other);
	bool operator==(const Rectangle& other);

	void setP1(const Point& _p1);
	Point getP1() const;

	void setP3(const Point& _p3);
	Point getP3() const;

	Point p2() const;
	Point p4() const;

	double diagonal() const;
	double length() const;
	double width() const;
	double perimeter() const;
	double area() const;

	bool isSquare() const;

	void points() const;
	void info() const;

private:
	Point p1, p3;
};

