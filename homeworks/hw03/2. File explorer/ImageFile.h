//62380
#pragma once
#include "File.h"

struct Resolution {
public:
	Resolution()
		: width(1024), height(768) {}

	Resolution(double w, double h)
		: width(w), height(h) {}

	void change(double w, double h) {
		this->width = w;
		this->height = h;
	}

	friend ostream& operator<<(ostream& out, const Resolution& object) {
		out << object.width << "x" << object.height;
		return out;
	}

private:
	double width, height;
};

class ImageFile : public File {
public:
	ImageFile(string n, string e, string d, Resolution r);

	string get_device() const;
	Resolution get_resolution() const;

	virtual Content* clone() const override;
	virtual void info() const override;

protected:
	string device;
	Resolution resolution;
};