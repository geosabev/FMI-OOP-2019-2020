//62380
#include "SVG.h"

SVG::SVG() {
	this->rectangles = nullptr;
	this->amount = 0;
}
SVG::SVG(Rectangle* _list, unsigned int _amount) {
	this->rectangles = new Rectangle[_amount];
	this->amount = _amount;

	for (unsigned int i = 0; i < this->amount; i++)
		this->rectangles[i] = _list[i];
}
SVG::~SVG() {
	delete[] this->rectangles;
}

void SVG::add(const Rectangle& _rect) {
	if (this->alreadyInList(_rect)) {
		cout << "Rectangle with same points already in list!" << endl;
		return;
	}

	Rectangle* temp = new Rectangle[this->amount + 1];

	for (unsigned int i = 0; i < this->amount; i++)
		temp[i] = this->rectangles[i];

	temp[this->amount] = _rect;

	delete[] this->rectangles;

	this->rectangles = new Rectangle[this->amount + 1];
	
	for (unsigned int i = 0; i < this->amount + 1; i++)
		this->rectangles[i] = temp[i];

	this->amount++;

	delete[] temp;

	cout << "New rectangle added!" << endl;
}
void SVG::add(const Point& _p1, const Point& _p3) {
	if (this->alreadyInList(Rectangle(_p1, _p3))) {
		cout << "Rectangle with same points already in list!" << endl;
		return;
	}

	Rectangle* temp = new Rectangle[this->amount + 1];

	for (unsigned int i = 0; i < this->amount; i++)
		temp[i] = this->rectangles[i];

	temp[this->amount].setP1(_p1);
	temp[this->amount].setP3(_p3);

	delete[] this->rectangles;

	this->rectangles = new Rectangle[this->amount + 1];

	for (unsigned int i = 0; i < this->amount + 1; i++)
		this->rectangles[i] = temp[i];

	this->amount++;

	delete[] temp;

	cout << "New rectangle added!" << endl;
}
void SVG::remove(unsigned int _index) {
	if (this->amount < _index) {
		cout << "No such rectangle in list!" << endl << endl;
		return;
	}

	Rectangle* temp = new Rectangle[this->amount];

	for (unsigned int i = 0; i < this->amount; i++)
		temp[i] = this->rectangles[i];

	delete[] this->rectangles;

	this->rectangles = new Rectangle[this->amount - 1];

	int currIdx = 0;

	for (unsigned int i = 0; i < this->amount; i++) {
		if (i == _index) {
			cout << "Rectangle with points:" << endl;
			temp[i].points();
			cout << "removed from the catalogue!" << endl;
			continue;
		}

		this->rectangles[currIdx] = temp[i];

		currIdx++;
	}

	this->amount--;

	delete[] temp;
}
bool SVG::alreadyInList(const Rectangle& _rect) const {
	for (unsigned int i = 0; i < this->amount; i++) {
		if (this->rectangles[i] == _rect) {
			return 1;
		}
	}

	return 0;
}

unsigned int SVG::biggestAreaIndex() const {
	unsigned int index = 0;
	double biggestArea = 0;

	for (unsigned int i = 0; i < this->amount; i++) {
		if (this->rectangles[i].area() > biggestArea) {
			biggestArea = this->rectangles[i].area();
			index = i;
		}
	}

	return index;
}

void SVG::list() const {
	cout << "All rectangles:" << endl;
	cout << "----------------------------------------------" << endl;

	for (unsigned int i = 0; i < this->amount; i++) {
		this->printByIndex(i);

		if (i < this->amount - 1)
			cout << endl;
	}

}
void SVG::printByIndex(unsigned int _index) const {
	cout << _index << ". ";
	this->rectangles[_index].info();
}