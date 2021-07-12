//62380
#pragma once
#include <iostream>
#include "Rectangle.h"
using namespace std;

class SVG {
public:
	SVG();
	SVG(Rectangle* _list, unsigned int _amount);
	~SVG();

	bool alreadyInList(const Rectangle& _rect) const;

	void add(const Rectangle& _newRect);
	void add(const Point& _bottomLeft, const Point& _topRight);
	void remove(unsigned int _index);

	unsigned int biggestAreaIndex() const;

	void list() const;
	void printByIndex(unsigned int _index) const;

private:
	Rectangle* rectangles;
	unsigned int amount;
};