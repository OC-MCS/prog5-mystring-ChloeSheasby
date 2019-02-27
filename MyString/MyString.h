#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
	char *str;							// a pointer to a char
public:
	MyString();							// default constructor
	MyString(const char *s);			// constructor
	MyString(const MyString& other);	// copy constructor
	~MyString();						// destructor
	MyString operator = (const MyString &other);	// overloaded assignment operator
	MyString operator + (const MyString &other);	// overloaded + operator
	bool operator == (const MyString &other);		// overloaded == operator
	char* c_str() const;							// returns the internal c-string pointer as a const pointer
};
