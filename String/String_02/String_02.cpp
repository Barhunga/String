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
	String* test_default = new String(); 
	String* test_02 = new String("Dragon elmo 2");
	const String* test_const = new String("French fry");  	 // still 2nd
	String* test_03 = new String(test_const->CStr()); 		 // still 2nd  

	// Printing function results
	
	// Print string length	
	cout << "\nPrinting string length\n";
	cout << test_02->Length() << endl;  

	// Print string
	cout << "\nPrinting string\n";
	cout << test_02->CStr() << endl; 
	test_03->WriteToConsole();  

	// Print character at index
	cout << "\nPrinting character at index\n";
	cout << test_02->CharacterAt(3) << endl;  
	cout << test_const->CharacterAt(4) << endl;  // calls const version of function

	// Print whether or not the string is the same as the input
	cout << "\nPrinting whether or not the string is the same as the input\n";
	cout << test_02->EqualTo("Dragon elmo 2") << endl;

	// Converting string to upper case and then printing it
	cout << "\nPrinting string in upper case\n";
	test_02->ToUpper();
	cout << test_02->CStr() << endl;

	// Converting string to lower case and then printing it
	cout << "\nPrinting string in lower case\n";
	test_02->ToLower(); 
	cout << test_02->CStr() << endl;  

	// Printing an input from the console
	cout << "\nPrinting an input from the console\n";
	test_default->ReadFromConsole(); 
	cout << test_default->CStr() << endl; 

	// Printing if the string is the same as another string
	cout << "\nPrinting if the string is the same as another string\n";
	cout << (test_02==test_03) << endl;  
	cout << (test_02!=test_03) << endl; 

	// Replacing one string as another
	cout << "\nReplacing one string as another\n";
	test_03 = test_default;  
	test_03->WriteToConsole();

}
