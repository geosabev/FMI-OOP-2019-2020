#include "Smartphone.h"

Smartphone::Smartphone(string b, string m, double p, unsigned int w, string _OS, double _display)
	: Product(b, m, p, w), OS(_OS), display(_display) {}

Product* Smartphone::clone() const{
	return new Smartphone(*this);
}

void Smartphone::specifications() const {
	cout << "Smartphone" << endl 
		<< "Display size: " << this->display << " inch" << endl
		<< "OS: " << this->OS << endl;
}

string Smartphone::getOS() const {
	return this->OS;
}
double Smartphone::getDisplay() const {
	return this->display;
}