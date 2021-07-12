//62380
#pragma once
#include "File.h"
#include "ImageFile.h"
#include "AudioFile.h"
#include "Folder.h"
using namespace std;

class FileExplorer {
public:
	FileExplorer();
	FileExplorer(string n);

	void add(Content* item);
	void add(Content* item, string folder);

	void search(string input) const;

private:
	Folder main_directory;
};
