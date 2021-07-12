//62380
#pragma once
#include "File.h"
#include "ImageFile.h"
#include "AudioFile.h"

class Folder : public Content {
public:
	Folder();
	Folder(string n);
	Folder(const Folder& other);
	Folder& operator=(const Folder& other);
	~Folder();

	template <class T>
	void addItem(const T& content);
	void addItem(Content* item);

	void deleteItem(string n);

	void search(string input) const;

	virtual Content* clone() const override;
	virtual void info() const override;

	Content* item(unsigned int index) const;
	unsigned int amount() const;

private:
	vector<Content*> items;
};

template <class T>
void Folder::addItem(const T& content) {
	Content* obj = new T(content);
	this->addItem(obj);
	delete obj;
}