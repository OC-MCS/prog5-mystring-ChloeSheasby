// Chloe Sheasby
// Programming Assignment #5
// Description: MyString
// Due Date: Friday, March 1st

#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

ostream& operator << (ostream& str, const MyString& other);		// function prototype for overloaded output

int main()
{
	MyString s1("hello");	// initializes an instance of MyString with a string, uses the constructor
	MyString s2("world");	// initializes an instance of MyString with a string, uses the constructor
	MyString s3(s1);		// initializes an instance of MyString with the info from another instance, uses the copy constructor
	MyString s4;			// initializes an instance of MyString with a nullpointer, uses the default constructor
	MyString s5;			// initializes an instance of MyString with a nullpointer, uses the default constructor

	s4 = s2;		// initializes s4 with the information from s2, uses the overloaded assignment operation

	s5 = s3 + " " + s2;	// initializes s5 with the concatenation of s3, a space, and s2, uses the overloaded + operator

	if (s1 == s4)	// compares s1 and s4, these should not equal each other, uses the overloaded == operator
	{
		cout << s1 << " and " << s4 << " equal each other" << endl;
	}
	else
	{
		cout << s1 << " and " << s4 << " do NOT equal each other" << endl;
	}

	if (s4 == s2)	// compares s4 and s2, these should equal each other
	{
		cout << s4 << " and " << s2 << " equal each other" << endl;
	}
	else
	{
		cout << s4 << " and " << s2 << " do NOT equal each other" << endl;
	}

	cout << s1 << endl;	// should output: hello
	cout << s2 << endl;	// should output: world
	cout << s3 << endl;	// should output: hello
	cout << s4 << endl;	// should output: world
	cout << s5 << endl;	// should output: hello world

	return 0;
}