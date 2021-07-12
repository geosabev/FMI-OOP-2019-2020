#include "Computer.h"

Computer::Computer(string b, string m, double p, unsigned int w, string cpu,
	string gpu, string os, unsigned int _storage, unsigned int _RAM)
	: Product(b, m, p, w), processor(cpu), graphicsCard(gpu), storage(_storage), RAM(_RAM) {}

void Computer::specifications() const {
	cout << "Processor: " << this->processor << endl
		<< "Graphics card: " << this->graphicsCard << endl
		<< "RAM: " << this->RAM << " GB, Storage: " << this->storage << " GB" << endl;
}

string Computer::getProcessor() const {
	return this->processor;
}
string Computer::getGraphicsCard() const {
	return this->graphicsCard;
}
string Computer::getOS() const {
	return this->OS;
}
unsigned int Computer::getStorage() const {
	return this->storage;
}
unsigned int Computer::getRAM() const {
	return this->RAM;
}