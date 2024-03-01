#include "String.h"
#include <iostream>
using namespace std;

String::String() {
	_string = new char[1];
	_string[0] = '\0';
	cout << "default constructor called\n";
}

String::String(const char* _str) {
	_string = new char[strlen(_str) + 1];
	for (size_t i = 0; i < Length(); i++) {
		_string[i] = _str[i];
	}
	//strcpy(_string, _str);
	cout << "2nd contstructor called\n";
}

String::String(const String& _other) {
	_string = new char[_other.Length() + 1];
	//for (size_t i = 0; i < Length(); i++) {
	//	_string[i] = _other[i];                // implement operator
	//}
	//strcpy(_string, _other._string);
	cout << "3rd contstructor called\n";
}

String::~String() {
	delete[] _string;
	_string = nullptr;
}

size_t String::Length() const
{
	size_t _length = 0;
	for (int i = 0; _string[i] != '\0'; i++) {
		_length++;
	}
	return _length;
}

char& String::CharacterAt(size_t _index)
{
	if (_index >= 0 && _index < Length()) {
		return _string[_index];
	}
	else {
		return _string[Length() - 1];
	}
}

const char& String::CharacterAt(size_t _index) const
{
	if (_index >= 0 && _index < Length()) {
		return _string[_index];
	}
	else {
		return '\0';
	}
}

bool String::EqualTo(const String& _other) const
{
	for (size_t i = 0; i < Length(); i++) {
		if (_string[i] != _other._string[i]) {
			return false;
		}
	}
	return true;
}

//String& String::Append(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
//String& String::Prepend(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
//const char* String::CStr() const
//{
//	return nullptr;
//}
//
//String& String::ToLower()
//{
//	// TODO: insert return statement here
//}
//
//String& String::ToUpper()
//{
//	// TODO: insert return statement here
//}
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
//
//String& String::ReadFromConsole()
//{
//	// TODO: insert return statement here
//}
//
//String& String::WriteToConsole()
//{
//	// TODO: insert return statement here
//}
//
//bool String::operator==(const String& _other)
//{
//	return false;
//}
//
//bool String::operator!=(const String& _other)
//{
//	return false;
//}
//
//String& String::operator=(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
//char& String::operator[](size_t _index)
//{
//	// TODO: insert return statement here
//}
//
//const char& String::operator[](size_t _index) const
//{
//	// TODO: insert return statement here
//}