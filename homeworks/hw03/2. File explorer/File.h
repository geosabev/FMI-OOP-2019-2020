//62380
#pragma once
#include "Content.h"

class File : public Content {
public:
	File(string n, string e);
	virtual ~File() = default;

	string get_extension() const;
	unsigned int get_size() const;

	virtual Content* clone() const override;
	virtual void info() const override;

	bool operator==(const File& other) const;

protected:
	string extension;
	unsigned int size;
};
