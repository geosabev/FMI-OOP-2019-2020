//62380
#include "Point.h"

double absolute(double _number) {
	if (_number < 0)
		return (_number * (-1));

	return _number;
}

Point::Point() {
	this->setX(0);
	this->setY(0);
}
Point::Point(double _x, double _y) {
	this->setX(_x);
	this->setY(_y);
}
Point& Point::operator=(const Point& other) {
	if (this == &other) {
		return *this;
	}

	this->setX(other.getX());
	this->setY(other.getY());

	return *this;
}

void Point::setX(double _x) {
	this->x = _x;
}
double Point::getX() const {
	return this->x;
}

void Point::setY(double _y) {
	this->y = _y;
}
double Point::getY() const {
	return this->y;
}

bool Point::operator==(const Point& other) const {
	return (this->getX() == other.getX() && this->getY() == other.getY());
}
bool Point::operator!=(const Point& other) const {
	return (this->getX() != other.getX() || this->getY() != other.getY());
}

void Point::print() const {
	cout << '(' << this->getX() << ", " << this->getY() << ')' << endl;
}

ostream& operator<<(ostream& out, const Point& _point) {
	out << '(' << _point.getX() << ", " << _point.getY() << ')';

	return out;
}
istream& operator>>(istream& in, Point& _point) {
	in >> _point.x >> _point.y;
	return in;
}

double distance(const Point& _p1, const Point& _p2) {
	double side1 = absolute(_p2.getX() - _p1.getX());
	double side2 = absolute(_p2.getY() - _p1.getY());

	return sqrt((side1 * side1) + (side2 * side2));
}

bool areOnSameLine(const Point& _p1, const Point& _p2) {
	return ((_p1.getX() == _p2.getX()) || (_p1.getY() == _p2.getY()));
}