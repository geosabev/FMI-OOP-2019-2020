#include "Laptop.h"

Laptop::Laptop(string b, string m, double p, unsigned int w, string cpu,
	string gpu, string os, unsigned int storage, unsigned int RAM)
	: Computer(b, m, p, w, cpu, gpu, os, storage, RAM) {}

Product* Laptop::clone() const {
	return new Laptop(*this);
}