#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

//====================================================================
// default constructor that intializes the instance with a nullpointer
//====================================================================
MyString::MyString()
{
	str = nullptr;
}

//====================================================================
// a constructor that initializes the instance with the desired string
//====================================================================
MyString::MyString(const char *s)
{
	int size = strlen(s) + 1;	// holds the size of the desired str with the string length of the passed string plus 1 for the nullbyte
	str = new char[size];		// dynamically allocates a new char array
	strcpy_s(str, size, s);		// copies the info from the stated string into the instance of MyString
}

//==========================================================================================
// a copy constructor that initializes an instance with another already initialized instance
//==========================================================================================
MyString::MyString(const MyString &other)
{
	cout << "The copy constructor is running now." << endl;	// this helps us know each time the copy constructor is used
	int size = strlen(other.str) + 1;	// holds the size of the desired str with the string length of the other instance plus 1 for the nullbyte
	str = new char[size];				// dynamically allocates a new char array
	strcpy_s(str, size, other.str);		// copies the info from the other instance into the instance of MyString
}

//===========================================================================
// a destructor that deletes the dynamically allocated memory whenever needed
//===========================================================================
MyString::~MyString()
{
	cout << "The destructor is running now." << endl;	// this helps us know each time the destructor is used
	delete[] str;	// deletes the dynamically allocated array
}

//=================================================================
// an overloaded assignment operator that allows the user to assign 
// one instance to another with just the equal sign ( = )
//=================================================================
MyString MyString::operator = (const MyString &other)
{
	if (this != &other)						// makes sure that the first instance is not the same as the instance the user wants to assign it
	{
		delete[] str;						// deletes the dynamically allocated array
		int size = strlen(other.str) + 1;	// holds the size of the desired str with the string length of the other instance plus 1 for the nullbyte
		str = new char[size];				// dynamically allocates a new char array
		strcpy_s(str, size, other.str);		// copies the info from the other instance into the instance of MyString
	}
	return *this;							// returns the first instance that is now initialized with a different instance
}

//====================================================================
// an overloaded + operator that allows the user to concatenate two or 
// more instances of MyString together with just the plus sign ( + )
//====================================================================
MyString MyString::operator + (const MyString &other)
{
	int size = strlen(str) + strlen(other.str) + 1;	// holds the size of the desired str with the string length of the first and other instance plus 1 for the nullbyte
	char* combined;					// a pointer to a char that will hold the new concatenated MyString
	combined = new char[size];		// dynamically allocates a new char array
	strcpy_s(combined, size, str);	// copies the info from the first instance into the new "combined" instance
	strcat_s(combined, size, other.str);	// places the info from the second instance onto the end of the new "combined" instance

	return combined;		// returns the new combined instance of MyString that now holds all the desired concatenated instances
}

//==============================================================
// an overloaded == operator that allows the user to compare two 
// instance of MyString with just the comparison symbol ( == )
//==============================================================
bool MyString::operator == (const MyString &other)
{
	bool same = false;		// holds a boolean value that will test if the instances are the same

	if (strcmp(str, other.str) == 0)	// strcmp will return 0 if the two instances are the same
	{
		same = true;
	}
	else
	{
		same = false;
	}
	return same;		// returns the boolean value initialized based on if the instances are the same or not
}

//=================================================================
// c_str() returns the pointer to a char so that it can be accessed 
// out of the member functions as it is a part of private
//=================================================================
char* MyString::c_str() const
{
	return str;
}

//=====================================================================
// overloaded output operator that allows the user to cout the instance 
// without having to access the separate parts of the instance
// this is not a member function
//=====================================================================
ostream& operator << (ostream& str, const MyString& other)
{
	str << other.c_str();	// this will output all of the information in every instance
	return str;
}