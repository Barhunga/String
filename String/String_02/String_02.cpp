#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	// Print "Hello, World"
	String* test = new String("Hello, World");
	cout << test->CStr() << endl; 


	// Testing

	// Making strings with different constructors
	String* test_default = new String(); 
	String* test_02 = new String("Dragon elmo"); 
	const String* test_const = new String("French fry");  	 // still 2nd
	String* test_03 = new String(test_const->CStr()); 		 // still 2nd 

	// Printing function results
	
	// Print string length	
	cout << test_02->Length() << endl;  

	// Print string
	cout << test_02->CStr() << endl; 

	// Print character at index
	cout << test_02->CharacterAt(40) << endl;  
	cout << test_const->CharacterAt(40) << endl;  

	// Print whether or not the string is the same as the input
	cout << test_02->EqualTo("Dragon elmo") << endl;


}
