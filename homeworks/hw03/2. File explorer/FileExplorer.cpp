//62380
#include "FileExplorer.h"

FileExplorer::FileExplorer()
	: main_directory("Main Directory") {}

FileExplorer::FileExplorer(string n)
	: main_directory(n) {}

void FileExplorer::add(Content* item) {
	this->main_directory.addItem(item);
}
void FileExplorer::add(Content* item, string folder) {
	unsigned int amount = this->main_directory.amount();

	for (unsigned int i = 0; i < amount; i++) {
		Folder* current = dynamic_cast<Folder*>(this->main_directory.item(i));

		if (current != nullptr) {
			if (current->get_name() == folder) {
				current->addItem(item);
				return;
			}
		}
	}

	Folder newFolder(folder);
	newFolder.addItem(item);

	this->main_directory.addItem(newFolder);
}

void FileExplorer::search(string input) const {
	cout << "Searching for: " << input << endl;
	this->main_directory.search(input);
}