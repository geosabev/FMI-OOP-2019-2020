//62380
#include "JSONObject.h"
#include "JSONArray.h"
#include "FileExplorer.h"
#include "Course.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Task 1: JSON
	JSONObject<int> o1("object1", 1);
	JSONObject<int> o2("object2", 2);
	JSONObject<int> o3("object3", 3);
	JSONObject<int> o4("object4", 4);
	JSONObject<int> o5("object5", 5);
	JSONObject<int> o6("object6", 6);

	JSONArray<int> a1, a2, a3, a4;

	a1.add(o1);
	a1.add(o2);
	a1.add(o3);
	a1.add(o4);

	a2.add(a1);
	a2.add(o5);

	a3.add(a2);
	a3.add(o6);

	a3.print();

	cout << endl << endl;

	cout << "Value of object with key object6: " << a3.get_value("object6") << endl;
	a3.remove("object6");

	//no object with such key
	try { cout << "Value of object with key object6: " << a1.get_value("object6") << endl; }
	catch (exception& e) { cerr << e.what() << endl; }

	try { a1.remove("object6"); }
	catch (exception& e) { cerr << e.what() << endl; }

	cout << endl;

	//Task 2: File explorer
	File file1("file", ".nfo");
	Folder folder1("Folder 1"), folder2("Folder 2"), folder3("Folder3");
	ImageFile img1("img", ".jpg", "Samsung Galaxy S7 Edge", Resolution(1024, 768));
	ImageFile img2("img", ".png", "Nokia", Resolution(100, 200));
	AudioFile audio1("POWER", "Kanye West", ".mp3", 2010);
	FileExplorer explorer("My Documents");

	folder1.addItem(file1);
	folder1.addItem(audio1);
	folder1.addItem(img1);

	folder2.addItem(folder1);
	folder2.addItem(img2);

	folder3.addItem(folder2);

	folder3.info();

	cout << endl;

	explorer.add(&folder1);
	explorer.add(&img2, "Folder 1");
	explorer.add(&img2, "Images");
	explorer.add(&img1);

	explorer.search("img");

	cout << endl;

	//Task 3: School system
	Student s1("Georgi Sabev", 62380);
	Teacher t1("Alexander Grigorov", Associate_Professor);
	Teacher t2("Simeon Zamkovoy", Associate_Professor);
	Course c1("OOP", Compulsory, 1, &t1);
	Course c2("Geometry", Compulsory, 2, &t2);

	s1.join_course(&c1);
	s1.join_course(&c2);

	s1.courses_list();
	cout << endl;
	c1.students_list();

	s1.leave_course(&c1);
	c2.remove_student(&s1);

	cout << endl;

	try { s1.courses_list(); }
	catch (exception& e) { cerr << e.what() << endl; }

	try { c1.students_list(); }
	catch (exception& e) { cerr << e.what() << endl; }
}