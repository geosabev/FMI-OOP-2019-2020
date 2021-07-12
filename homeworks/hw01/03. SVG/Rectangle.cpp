//62380
#include "Rectangle.h"

Rectangle::Rectangle() {
	this->setP1(Point(0, 1));
	this->setP3(Point(1, 0));
}
Rectangle::Rectangle(const Point& _p1, const Point& _p3) {
	if ((_p1 == _p3) || areOnSameLine(_p1, _p3)) {
		cout << "Invalid coordinates!" << endl;
		return;
	}

	if (_p1.getY() > _p3.getY()) {
		this->setP1(_p3);
		this->setP3(_p1);
	}

	this->setP1(_p1);
	this->setP3(_p3);
}
Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (this == &other) {
		return *this;
	}

	this->setP1(other.getP1());
	this->setP3(other.getP3());

	return *this;
}
bool Rectangle::operator==(const Rectangle& other) {
	if (this->getP1() == other.getP1() && this->getP3() == other.getP3())
		return 1;
	else if (this->getP1() == other.getP3() && this->getP3() == other.getP1())
		return 1;

	return 0;
}

void Rectangle::setP1(const Point& _p1) {
	this->p1 = _p1;
}
Point Rectangle::getP1() const {
	return this->p1;
}

void Rectangle::setP3(const Point& _p3) {
	this->p3 = _p3;
}
Point Rectangle::getP3() const {
	return this->p3;
}

Point Rectangle::p2() const {
	Point point2(this->p3.getX(), this->p1.getY());
	return point2;
}
Point Rectangle::p4() const {
	Point point4(this->p1.getX(), this->p3.getY());
	return point4;
}

bool Rectangle::isSquare() const {
	return (this->length() == this->width());
}

double Rectangle::length() const {
	double length = this->p3.getX() - this->p1.getX();
	return absolute(length);
}
double Rectangle::width() const {
	double width = this->p3.getY() - this->p1.getY();
	return absolute(width);
}

double Rectangle::diagonal() const {
	return sqrt(this->length()*this->length() + this->width()*this->width());
}

double Rectangle::perimeter() const {
	return (2 * (this->length() + this->width()));
}
double Rectangle::area() const {
	return (this->length() * this->width());
}

void Rectangle::points() const {
	cout << "P1" << getP1() << ", ";
	cout << "P2" << p2() << ", ";
	cout << "P3" << getP3() << ", ";
	cout << "P4" << p4() << endl;
}
void Rectangle::info() const {
	cout << "Points: "; this->points();
	cout << "Length = " << this->length() << ", Width = " << this->width() << endl;
	cout << "Diagonal = " << this->diagonal() << endl;
	cout << "Perimeter = " << this->perimeter() << ", Area = " << this->area() << endl;

	cout << "It is ";
	if (this->isSquare())
		cout << "a square." << endl;
	else cout << "not a square." << endl;
}