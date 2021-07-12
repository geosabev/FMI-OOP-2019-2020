//62380
/*
#include <iostream>
#include "SVG.h"
using namespace std;

Rectangle testList[6] = { Rectangle(Point(0, 0), Point(1, 1)),
						  Rectangle(Point(0, 0), Point(1, 2)),
						  Rectangle(Point(0, 1), Point(1, 0)),
						  Rectangle(Point(0, 2), Point(3, 7)),
						  Rectangle(Point(4, -3), Point(7, 12)),
						  Rectangle(Point(1, 3), Point(2, 4)) };

//For separating tests
void line() {
	cout << "//////////////////////////////////////////////\n";
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);			//memory leak test

	line();

	//Invalid rectangles - same points or laying on same line!
	Rectangle a(Point(1, 1), Point(1, 1));
	Rectangle b(Point(1, 2), Point(1, 3));
	Rectangle c(Point(1, 2), Point(3, 2));

	line();

	//Constructors
	Point p1, p2(1, 2);
	Rectangle r1(p1, p2);
	r1.info();

	cout << endl;

	Rectangle r2(Point(1, 4), Point(5, 8));
	r2.info();

	cout << endl;

	Rectangle r3 = r2;
	r3.info();

	line();

	//SVG - adding, removing, list, printing by index, finding the one with largest area
	SVG test(testList, 6);

	test.add(r3);
	test.add(Point(), Point(8, 9));

	line();

	test.list();

	Point p3(5, 6), p4(6, 7);
	Rectangle r4(p3, p4), r5(p4, p3);

	line();

	test.add(r5);

	line();

	test.add(r4);

	line();

	cout << "Rectangle with biggest area: " << test.biggestAreaIndex() << endl << endl;
	test.printByIndex(test.biggestAreaIndex());

	line();

	test.remove(test.biggestAreaIndex());

	line();

	cout << "Rectangle with biggest area: " << test.biggestAreaIndex() << endl << endl;
	test.printByIndex(test.biggestAreaIndex());

	line();
}
*/