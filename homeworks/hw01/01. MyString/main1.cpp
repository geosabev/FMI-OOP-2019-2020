//62380
/*
#include <iostream>
#include "MyString.h"
using namespace std;

//For better separating
void line() {
	cout << "//////////////////////////////////////////////\n";
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);			//memory leak test

	char word[8] = "String";
	char sentence[27] = "This is my class MyString.";

	line();

	//constructors
	MyString s1, s2("String"), s3(word), s4 = "String", s5(s2), s6 = s5, s7(10, '='), s8(sentence, 16);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s6: " << s6 << endl;
	cout << "s7: " << s7 << endl;
	cout << "s8: " << s8 << endl;

	line();

	//operator + (3 cases)
	MyString s9, leftStr("LeftStr_"), rightStr("_RightStr");
	char leftCC[8] = "LeftCC_", rightCC[9] = "_RightCC";
	s9 = leftStr + rightStr;
	cout << "s9: " << s9 << endl;
	s9 = leftCC + rightStr;
	cout << "s9: " << s9 << endl;
	s9 = leftStr + rightCC;
	cout << "s9: " << s9 << endl;

	line();

	//operator += (2 cases)
	MyString s10("operator+="), addStr(" is powerful");
	char addCC[28] = " and now even more powerful";
	s10 += addStr;
	cout << "s10: " << s10 << endl;
	s10 += addCC;
	cout << "s10: " << s10 << endl;

	line();

	//popBack and append
	MyString s11("Hello, World");
	cout << "s11: " << s11 << endl;
	s11.popBack();
	cout << "after popBack: " << s11 << endl;
	s11.append('t');
	cout << "after append t: " << s11 << endl;
	s11.popBack();
	cout << "after popBack: " << s11 << endl;
	s11.append("d!");
	cout << "after append d!: " << s11 << endl;

	line();

	//using popBack on an empty string
	cout << "s1: " << s1 << endl;
	s1.popBack();

	line();
	 
	//index operator
	for (int i = 0; i < s2.length(); i++)
		cout << "index " << i << ". :" << s2[i] << endl;

	line();

	//relational operators (==, !=, <, >, <=, >=)
	MyString c1 = "abc";
	MyString c2 = "ABC";
	cout << "comparing: " << '"' << c1 << '"' << " to " << '"' << c2 << '"' << endl;
	cout << (c1 == c2) << " equal" << endl;
	cout << (c1 != c2) << " not equal" << endl;
	cout << (c1 >= c2) << " greater than or equal to" << endl;
	cout << (c1 <= c2) << " less than or equal to" << endl;
	cout << (c1 > c2) << " greater than" << endl;
	cout << (c1 < c2) << " less than" << endl;

	cout << endl;

	MyString c3 = "ABC";
	MyString c4 = "ABC";
	cout << "comparing: " << '"' << c3 << '"' << " to " << '"' << c4 << '"' << endl;
	cout << (c3 == c4) << " equal" << endl;
	cout << (c3 != c4) << " not equal" << endl;
	cout << (c3 >= c4) << " greater than or equal to" << endl;
	cout << (c3 <= c4) << " less than or equal to" << endl;
	cout << (c3 > c4) << " greater than" << endl;
	cout << (c4 < c4) << " less than" << endl;

	cout << endl;

	MyString c5;
	MyString c6 = "abcde";
	cout << "comparing: " << '"' << c5 << '"' << " to " << '"' << c6 << '"' << endl;
	cout << (c5 == c6) << " equal" << endl;
	cout << (c5 != c6) << " not equal" << endl;
	cout << (c5 >= c6) << " greater than or equal to" << endl;
	cout << (c5 <= c6) << " less than or equal to" << endl;
	cout << (c5 > c6) << " greater than" << endl;
	cout << (c5 < c6) << " less than" << endl;

	line();

	//i/o operators
	//MyString input;
	//cin >> input;
	//cout << input;
	
}*/