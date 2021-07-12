//62380
#include "ImageFile.h"

ImageFile::ImageFile(string n, string e, string d, Resolution r)
	: File(n, e), device(d), resolution(r) {}

string ImageFile::get_device() const {
	return this->device;
}
Resolution ImageFile::get_resolution() const {
	return this->resolution;
}

Content* ImageFile::clone() const {
	return new ImageFile(*this);
}

void ImageFile::info() const {
	File::info();
	cout << "Image resolution: " << this->resolution << endl;
	cout << "Made on: " << this->device << endl;
}