//62380
#include <iostream>
#include "MyString.h"
#include "Counter.h"
#include "JSONObject.h"
#include "JSONArray.h"
using namespace std;

JSONObject<int> test[5] = { JSONObject<int>("value1", 1),
								 JSONObject<int>("value2", 2),
								 JSONObject<int>("value3", 3),
								 JSONObject<int>("value4", 4),
								 JSONObject<int>("value5", 5)
};

int main() {
	//memory leak test
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Task 1: Add I/O operators (<</>>)
	{
		MyString input;
		cout << "Input string: "; cin >> input;
		cout << "Your input: "; cout << input << endl;

		cout << endl;

		//P.S. fixed lexicographical comparison in compare() method
		//	   and removed code repetition in overloaded operators
	}

	//Task 2: Make Counter class and its functions templates
	{
		MyString* value = new MyString("It even works for my string class, damn!");
		Counter<MyString> ptr(value);
		cout << "Reference count through the scopes: " << ptr.getCount() << ' ';
		{
			Counter<MyString> ptr2 = ptr;
			{
				Counter<MyString> ptr3 = ptr2;
				cout << ptr.getCount() << ' ';
				{
					Counter<MyString> ptr4 = ptr2;
					{
						Counter<MyString> ptr5 = ptr4;
						cout << ptr.getCount() << ' ';
					}
				}
			}
			cout << ptr.getCount() << ' ';
		}
		cout << ptr.getCount() << endl;
		cout << "Value of ptr: " << ptr.getValue() << endl;

		cout << endl;

		//P.S. added deletion in operator=
	}

	//Task 3 and Task 4: class JSONObject, class JSONArray & writeOutput()
	{
		JSONObject<MyString> obj1("name", "Georgi");
		JSONObject<int> obj2("age", 20);
		JSONObject<bool> obj3("employed", false);
		
		cout << obj1 << endl << obj2 << endl;

		JSONArray<int> arr(test, 5);

		arr.add(obj2);
		arr.add("faculty number", 62380);

		arr.print();

		arr.remove("value4");

		cout << arr.value("faculty number") << endl;

		cout << endl;

		arr.writeOutput("log.txt");
	}
}