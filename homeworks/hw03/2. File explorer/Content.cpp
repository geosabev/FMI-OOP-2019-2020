//62380
#include "Content.h"

Content::Content(string n)
	: name(n)
{
	this->set_date();
}

bool Content::operator==(const Content& other) const {
	if (this->name == other.name)
		return true;

	return false;
}

string Content::get_name() const {
	return this->name;
}
string Content::get_date() const {
	return this->date;
}

void Content::set_name(string n) {
	this->name = n;
}
void Content::set_date() {
	time_t current = chrono::system_clock::to_time_t(chrono::system_clock::now());
	this->date = ctime(&current);
}