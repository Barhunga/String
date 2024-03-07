#include <iostream>
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

	// Print string
	cout << "\nPrinting string\n";
	cout << test_04->CStr() << endl;
	test_03->WriteToConsole();

	// Print string length	
	cout << "\nPrinting string length\n";
	cout << test_02->CStr() << ": " << test_02->Length() << endl;

	// Print character at index
	cout << "\nPrinting character at index\n";
	cout << "Character at index 3 in " << test_02->CStr() << ": " << test_02->CharacterAt(3) << endl;
	cout << "Character at index 4 in " << test_const->CStr() << ": " << test_const->CharacterAt(4) << endl;  // Calls const version of function

	// Print whether or not the string is the same as the input
	cout << "\nPrinting whether or not the string is the same as the input\n";
	cout << "Is " << test_02->CStr() << " == Dragon elmo 2? " << test_02->EqualTo("Dragon elmo 2") << endl;
	cout << "Is " << test_02->CStr() << " == Dragon elmo 3? " << test_02->EqualTo("Dragon elmo 3") << endl;

	// Adding another string to the end of a string
	cout << "\nAdding another string to the end of a string\n";
	cout << "Adding " << test_03->CStr() << " to the end of " << test_02->CStr() << endl;
	test_02->Append(test_03->CStr());
	cout << test_02->CStr() << endl;

	// Adding another string to the start of a string
	cout << "\nAdding another string to the start of a string\n";
	cout << "Adding " << test_03->CStr() << " to the start of " << test_02->CStr() << endl;
	test_02->Prepend(test_03->CStr());
	cout << test_02->CStr() << endl;

	// Converting string to upper case and then printing it
	cout << "\nPrinting string in upper case\n";
	test_02->ToUpper();
	cout << test_02->CStr() << endl;

	// Converting string to lower case and then printing it
	cout << "\nPrinting string in lower case\n";
	test_02->ToLower();
	cout << test_02->CStr() << endl;

	// Find location of string in another string
	cout << "\nPrinting location of string in another string\n";
	cout << "Printing location of fry in " << test_02->CStr() << endl << test_02->Find("fry") << endl;
	cout << "Printing location of fry in " << test_02->CStr() << " starting from index 8" << endl << test_02->Find(8, "fry") << endl;

	// Replace a found string (within a string) with another string
	cout << "\nReplace a found string (within a string) with another string\n";
	cout << "Replacing all instances of fry with fries in " << test_02->CStr() << endl;
	test_02->Replace("fry", "fries");
	cout << test_02->CStr() << endl << endl;

	cout << "Replacing all instances of fries with fry in " << test_02->CStr() << endl;
	test_02->Replace("fries", "fry");
	cout << test_02->CStr() << endl;

	// Printing an input from the console
	cout << "\nPrinting an input from the console\n";
	test_default->ReadFromConsole();
	cout << test_default->CStr() << endl;

	// Printing if the string is the same as another string
	cout << "\nPrinting if the string is the same as another string\n";
	cout << "Is " << test_02->CStr() << " the same as " << test_03->CStr() << "? " << (*test_02 == *test_03) << endl;
	cout << "Is " << test_02->CStr() << " NOT the same as " << test_03->CStr() << "? " << (*test_02 != *test_03) << endl;

	// Replacing one string as another
	cout << "\nReplacing one string as another\n";
	cout << "Replacing " << test_03->CStr() << " with " << test_default->CStr() << endl;
	*test_03 = *test_default;
	test_03->WriteToConsole();

}
