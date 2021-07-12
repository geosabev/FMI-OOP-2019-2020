//62380
#pragma once
#include "File.h"

class AudioFile : public File {
public:
	AudioFile(string t, string a, string e, unsigned int y);

	string get_title() const;
	string get_artist() const;
	unsigned int get_year() const;

	virtual Content* clone() const override;
	virtual void info() const override;

protected:
	string title, artist;
	unsigned int year;
};