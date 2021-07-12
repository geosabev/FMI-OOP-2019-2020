//62380
#include "AudioFile.h"

AudioFile::AudioFile(string t, string a, string e, unsigned int y)
	: File(a + " - " + t, e), title(t), artist(a), year(y) {}

string AudioFile::get_title() const {
	return this->title;
}
string AudioFile::get_artist() const {
	return this->artist;
}
unsigned int AudioFile::get_year() const {
	return this->year;
}

Content* AudioFile::clone() const {
	return new AudioFile(*this);
}

void AudioFile::info() const {
	File::info();
	cout << "Song title: " << this->title << endl;
	cout << "Artist: " << this->artist << endl;
	cout << "Year of release: " << this->year << endl;
}
