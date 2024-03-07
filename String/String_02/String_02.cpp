#include <iostream>
#include <fstream>
#include "String.h"
using namespace std;

int main()
{
	// Print "Hello, World"
	String* test = new String("Hello, World");
	cout << test->CStr() << endl << endl;


	// Testing

	// Making strings with different constructors
	String* test_default = new String(); 					 // Default constructor
	String* test_02 = new String("Dragon elmo 2");			 // Second constructor
	const String* test_const = new String("French fry");  	 // Second constructor
	String* test_03 = new String(test_const->CStr()); 		 // Second constructor
	String* test_04 = new String(*test_02);     			 // Copy constructor

	// Printing function results

	ofstream write_file;
	write_file.open("Log.txt");

	// Print string
	write_file << "\nPrinting string\n";
	write_file << test_04->CStr() << endl;
	test_03->WriteToConsole();

	// Print string length	
	write_file << "\nPrinting string length\n";
	write_file << test_02->CStr() << ": " << test_02->Length() << endl;

	// Print character at index
	write_file << "\nPrinting character at index\n";
	write_file << "Character at index 3 in " << test_02->CStr() << ": " << test_02->CharacterAt(3) << endl;
	write_file << "Character at index 4 in " << test_const->CStr() << ": " << test_const->CharacterAt(4) << endl;  // Calls const version of function

	// Print whether or not the string is the same as the input
	write_file << "\nPrinting whether or not the string is the same as the input\n";
	write_file << "Is " << test_02->CStr() << " == Dragon elmo 2? " << test_02->EqualTo("Dragon elmo 2") << endl;
	write_file << "Is " << test_02->CStr() << " == Dragon elmo 3? " << test_02->EqualTo("Dragon elmo 3") << endl;

	// Adding another string to the end of a string
	write_file << "\nAdding another string to the end of a string\n";
	write_file << "Adding " << test_03->CStr() << " to the end of " << test_02->CStr() << endl;
	test_02->Append(test_03->CStr());
	write_file << test_02->CStr() << endl;

	// Adding another string to the start of a string
	write_file << "\nAdding another string to the start of a string\n";
	write_file << "Adding " << test_03->CStr() << " to the start of " << test_02->CStr() << endl;
	test_02->Prepend(test_03->CStr());
	write_file << test_02->CStr() << endl;

	// Converting string to upper case and then printing it
	write_file << "\nPrinting string in upper case\n";
	test_02->ToUpper();
	write_file << test_02->CStr() << endl;

	// Converting string to lower case and then printing it
	write_file << "\nPrinting string in lower case\n";
	test_02->ToLower();
	write_file << test_02->CStr() << endl;

	// Find location of string in another string
	write_file << "\nPrinting location of string in another string\n";
	write_file << "Printing location of fry in " << test_02->CStr() << endl << test_02->Find("fry") << endl;
	write_file << "Printing location of fry in " << test_02->CStr() << " starting from index 8" << endl << test_02->Find(8, "fry") << endl;

	// Replace a found string (within a string) with another string
	write_file << "\nReplace a found string (within a string) with another string\n";
	write_file << "Replacing all instances of fry with fries in " << test_02->CStr() << endl;
	test_02->Replace("fry", "fries");
	write_file << test_02->CStr() << endl << endl;

	write_file << "Replacing all instances of fries with fry in " << test_02->CStr() << endl;
	test_02->Replace("fries", "fry");
	write_file << test_02->CStr() << endl;

	// Printing an input from the console
	write_file << "\nPrinting an input from the console\n";
	test_default->ReadFromConsole();
	write_file << test_default->CStr() << endl;

	// Printing if the string is the same as another string
	write_file << "\nPrinting if the string is the same as another string\n";
	write_file << "Is " << test_02->CStr() << " the same as " << test_03->CStr() << "? " << (*test_02 == *test_03) << endl;
	write_file << "Is " << test_02->CStr() << " NOT the same as " << test_03->CStr() << "? " << (*test_02 != *test_03) << endl;

	// Replacing one string as another
	write_file << "\nReplacing one string as another\n";
	write_file << "Replacing " << test_03->CStr() << " with " << test_default->CStr() << endl;
	*test_03 = *test_default;
	test_03->WriteToConsole();

	write_file.close();

}
