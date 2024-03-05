//#define _CRT_SECURE_NO_WARNINGS         // for use with strcpy and strcat
#include "String.h"
#include <iostream>
using namespace std;

// Default constructor
String::String() {
	_string = new char[1];
	_string[0] = '\0';
	cout << "default constructor called\n";
}

// Constructor for characters
String::String(const char* _str) {
	_string = new char[strlen(_str) + 1];
	for (size_t i = 0; i < Length(); i++) {
		_string[i] = _str[i];
	}
	//strcpy(_string, _str);			   //    <- Alternative with _CRT_SECURE_NO_WARNINGS
	cout << "2nd constructor called\n";
}

// Copy constructor?????????
String::String(const String& _other) {
	_string = new char[_other.Length() + 1];
	for (size_t i = 0; i < Length(); i++) {
		_string[i] = _other[i];                
	}
	//strcpy(_string, _other._string);	   //    <- Alternative with _CRT_SECURE_NO_WARNINGS
	//_string = _other._string;			   //    <- Alternative (needs testing)
	cout << "3rd constructor called\n";
}

// Destructor
String::~String() {
	delete[] _string;
	_string = nullptr;
}

// Returns an integer representing the length of the string
size_t String::Length() const
{
	size_t _length = 0;
	for (int i = 0; _string[i] != '\0'; i++) {
		_length++;
	}
	return _length;
}

// Returns character at _index 
char& String::CharacterAt(size_t _index)
{
	if (_index >= 0 && _index < Length()) { // If index is in range of the string, returns the character at index
		return _string[_index];
	}
	else {
		return _string[Length()]; // Returns null terminator
	}
}

// Returns character at _index (const version)
const char& String::CharacterAt(size_t _index) const
{
	if (_index >= 0 && _index < Length()) {
		return _string[_index];
	}
	else {
		return '\0'; 
	}
}

// Returns true if _other contains the same characters.
bool String::EqualTo(const String& _other) const
{
	for (size_t i = 0; i < Length(); i++) {
		if (_string[i] != _other._string[i]) {
			return false;
		}
	}
	return true;
	//if (strcmp(_string, _other._string) == 0) {	//	<- Alternative
	//	return true;
	//}
	//return false;
}

// Adds str to the end of the string
String& String::Append(const String& _str)
{
	// Create new empty string with length of both strings combined 
	size_t new_length = Length() + _str.Length();
	char* new_string = new char[new_length + 1];

	// Copy first string to the new string
	for (size_t i = 0; i < Length(); i++) {  
		new_string[i] = _string[i];
	}
	// strcpy(new_string, _string);       //  <- Alternative with _CRT_SECURE_NO_WARNINGS
	
	// Copy second string to index after first string in the new string
	for (size_t i = 0; i < new_length; i++) { 
		new_string[i + Length()] = _str[i];
	}
	 //strcat(new_string, _str._string);  //  <- Alternative with _CRT_SECURE_NO_WARNINGS

	// Delete old string data, assign string to the new string created
	delete[] _string;
	_string = new_string;
	return *this;
}

// Adds str to the beginning of the string
String& String::Prepend(const String& _str)
{
	// Create new empty string with length of both strings combined 
	size_t new_length = Length() + _str.Length(); 
	char* new_string = new char[new_length + 1]; 

	// Copy second string to the new string 
	for (size_t i = 0; i < _str.Length(); i++) {
		new_string[i] = _str[i]; 
	}
	 //strcpy(new_string, _str._string);  //  <- Alternative with _CRT_SECURE_NO_WARNINGS

	// Copy first string to index after second string in the new string
	for (size_t i = 0; i < new_length; i++) {  
		new_string[i + _str.Length()] = _string[i]; 
	}
	 //strcat(new_string, _string);       //  <- Alternative with _CRT_SECURE_NO_WARNINGS

	// Delete old string data, assign string to the new string created
	delete[] _string; 
	_string = new_string; 
	return *this;
}

// Return the const char * that is useable with std::cout
const char* String::CStr() const
{
	return _string;
}

// Return 
String& String::ToLower()
{
	for (int i = 0; i < Length(); i++) {
		if (_string[i] >= 65 && _string[i] <= 92) { // If uppercase character
			_string[i] += 32;
		}
		//_string[i] = tolower(_string[i]);   //  <- Alternative
	}
	return *this;
}

String& String::ToUpper()
{
	for (int i = 0; i < Length(); i++) {
		if (_string[i] >= 97 && _string[i] <= 122) { // If lowercase character
			_string[i] -= 32;
		}
		//_string[i] = toupper(_string[i]);   //  <- Alternative
	}
	return *this;
}
//
//size_t String::Find(const String& _str)
//{
//	return size_t();
//}
//
//size_t String::Find(size_t _startIndex, const String& _str)
//{
//	return size_t();
//}
//
//String& String::Replace(const String& _find, const String& _replace)
//{
//	// TODO: insert return statement here
//}

// Wait for input in the console window and store the result
String& String::ReadFromConsole()
{
	cout << "Enter string\n";
	char input[1000];
	cin.getline(input, 1000);  
	*this = input; 
	return *this;
}

// Write the string to the console window.
String& String::WriteToConsole()
{
	cout << _string << endl;
	return *this;
}

//  Returns true if lhs == rhs
bool String::operator==(const String& _other)
{
	return EqualTo(_other) == 0;
}

// Returns true if lhs != rhs
bool String::operator!=(const String& _other)
{
	return !(*this == _other);
}

// Replaces the characters in lhs with the characters in rhs
String& String::operator=(const String& _str)
{
	delete[] _string;
	_string = new char[_str.Length() + 1];
	for (size_t i = 0; i < Length(); i++) { 
		_string[i] = _str[i]; 
	} 
	//strcpy(_string, _str._string);			 // Alternative with _CRT_SECURE_NO_WARNINGS
	return *this;
}

// Returns the character located at index
char& String::operator[](size_t _index)
{
	return _string[_index];
}

// Returns the character located at index (const version)
const char& String::operator[](size_t _index) const
{
	return _string[_index];
}