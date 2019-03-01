// Chloe Sheasby
// Programming Assignment #5
// Description: MyString
// Due Date: Friday, March 1st

#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

ostream& operator << (ostream& str, const MyString& other);		// function prototype for overloaded output since it is not a member function of MyString
void compare(MyString s1, MyString s2);		
MyString assignName(MyString s);

int main()
{
	cout << "Assigning 'hello' to s1 using the constructor." << endl;
	MyString s1("hello");	// initializes an instance of MyString with a string, uses the constructor
	cout << "After assignment:" << endl;
	cout << "s1: " << s1 << endl << endl;

	cout << "Assigning 'world' to s2 using the constructor." << endl;
	MyString s2("world");	// initializes an instance of MyString with a string, uses the constructor
	cout << "After assignment:" << endl;
	cout << "s2: " << s2 << endl << endl;

	cout << "Assigning " << s1 << " (s1) to s3 using the copy constructor." << endl;
	MyString s3(s1);		// initializes an instance of MyString with the info from another instance, uses the copy constructor
	cout << "After assignment:" << endl;
	cout << "s3: " << s3 << endl << endl;

	cout << "Using the default constructor to initialize s4, s5, s6, and s7 with a nullpointer." << endl << endl;
	MyString s4;			// initializes an instance of MyString with a nullpointer, uses the default constructor
	MyString s5;			// initializes an instance of MyString with a nullpointer, uses the default constructor
	MyString s6;			// initializes an instance of MyString with a nullpointer, uses the default constructor
	MyString s7;			// initializes an instance of MyString with a nullpointer, uses the default constructor

	cout << "Assigning " << s3 << " (s3) to s7 (nullpointer) using the overloaded assignment operator." << endl;
	s7 = s3;			// initializes s7 with the information from s3, uses the overloaded assignment operator
	cout << "After assignment: " << endl;
	cout << "s3: " << s3 << endl;
	cout << "s7: " << s7 << endl << endl;

	cout << "Assigning " << s2 << " (s2) to s4 (nullpointer) and s4 (nullpointer) to s6 (nullpointer) using the overloaded assignment operator." << endl;
	s6 = s4 = s2;		// initializes s4 with the information from s2 and s6 with the information from s4, uses the overloaded assignment operation
	cout << "After assignment: " << endl;
	cout << "s2: " << s2 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s6: " << s6 << endl << endl;

	cout << "Assigning the concatenation of " << s3 << " (s3), a space, and " << s2 << " (s2) to s5 (nullpointer) using the overloaded + operator." << endl;
	s5 = s3 + " " + s2;	// initializes s5 with the concatenation of s3, a space, and s2, uses the overloaded + operator
	cout << "After assignment: " << endl;
	cout << "s3: " << s3 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s5: " << s5 << endl << endl;

	cout << "Comparing " << s1 << " (s1) and " << s4 << " (s4), passing the MyStrings to a function that uses the overloaded == operator." << endl;
	compare(s1, s4);	// function call, compares s1 and s4, these should not be the same, uses the overloaded == operator
	cout << "s1: " << s1 << endl;
	cout << "s4: " << s4 << endl << endl;

	cout << "Comparing " << s4 << " (s4) and " << s2 << " (s2), passing the MyStrings to a function that uses the overloaded == operator." << endl;
	compare(s4, s2);	// function call, compares s4 and s2, these should be the same
	cout << "s4: " << s4 << endl;
	cout << "s2: " << s2 << endl << endl;

	cout << "Assigning Randy to " << s4 << " (s4) by passing the MyString to a function to demonstrate versatility." << endl;
	s4 = assignName(s4);		// function call, makes sure that changing s4 will not change s6
	cout << "After assignment: " << endl;
	cout << "s4: " << s4 << endl << endl;
	
	cout << "Checking if changing " << s4 << " (s4) changed " << s6 << " (s6), using the comparison function again." << endl;
	compare(s4, s6);		// function call, compares s4 and s6, these should be the same
	cout << "s4: " << s4 << endl;
	cout << "s6: " << s6 << endl;

	return 0;
}

//================================================================
// this receives two MyStrings as parameters and couts statements 
// depending on if the two MyStrings are the same or not
// demonstrates the versatility of the MyString class
//================================================================
void compare(MyString s1, MyString s2)
{
	if (s1 == s2)		// uses the overloaded == operator
		cout << s1 << " and " << s2 << " are exactly the same." << endl;
	else
		cout << s1 << " and " << s2 << " are NOT the same." << endl;
}

//=============================================================
// this recieves one MyString as a parameter and re-assigns the 
// name, Randy, to the MyString
// it then returns the re-assigned MyString
// again, this demonstrates versatility of the MyString class
//=============================================================
MyString assignName(MyString s)
{
	s = "Randy";	// assigns Randy to the MyString
	return s;
}