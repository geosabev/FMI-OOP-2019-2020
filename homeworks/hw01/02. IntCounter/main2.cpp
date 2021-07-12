//62380
/*
#include <iostream>
#include "IntCounter.h"
using namespace std;

//For better separating
void line() {
	cout << "\n//////////////////////////////////////////////\n";
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);			//memory leak test
	
	//1 3 5 2 1
	int* value = new int(1);
	IntCounter test(value);
	cout << test.getCount() << ' ';
	{
		IntCounter copyTest = test;
		{
			IntCounter copyCopy = copyTest;
			cout << test.getCount() << ' ';
			{
				IntCounter insideCopy = copyTest;
				{
					IntCounter insideCopyCopy = insideCopy;
					cout << test.getCount() << ' ';
				}
			}
		}
		cout << test.getCount() << ' ';
	}
	cout << test.getCount();

	line();
	
	//1 2 3 2
	int* some_number = new int(5);
	IntCounter first(some_number);
	cout << first.getCount() << ' ';
	IntCounter second = first;
	cout << first.getCount() << ' ';
	{
		IntCounter third(second);
		cout << first.getCount() << ' ';
	}
	cout << first.getCount();

	line();

	//1 1
	int* n1 = new int(5);
	int* n2 = new int(7);
	IntCounter nFirst(n1);
	IntCounter nSecond(n2);
	cout << nFirst.getCount() << ' ';
	cout << nSecond.getCount();

	line();

	//1 2
	int* nullNum = nullptr;
	IntCounter one(nullNum);
	cout << one.getCount() << ' ';
	IntCounter two = one;
	cout << one.getCount();

	line();

	//1 2 3 2
	IntCounter start(nullNum);
	cout << start.getCount() << ' ';
	IntCounter mid = start;
	cout << start.getCount() << ' ';
	{
		IntCounter final = mid;
		cout << start.getCount() << ' ';
	}
	cout << start.getCount();

	line();
}
*/