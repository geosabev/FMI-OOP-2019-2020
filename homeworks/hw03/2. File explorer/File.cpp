//62380
#include "File.h"
using namespace std;

File::File(string n, string e)
	: Content(n), extension(e), size(0) {}

string File::get_extension() const {
	return this->extension;
}
unsigned int File::get_size() const {
	return this->size;
}

Content* File::clone() const {
	return new File(*this);
}

void File::info() const {
	cout << "Name: " << this->name << this->extension << endl;
	cout << "Date created: " << this->date;
	cout << "Size: " << this->size << " MB"<< endl;
}

bool File::operator==(const File& other) const {
	if (Content::operator==(other) == true)
		if (this->extension == other.extension)
			return true;

	return false;
}
