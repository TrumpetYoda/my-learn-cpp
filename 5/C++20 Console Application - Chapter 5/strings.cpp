/*

Introducing std::string:

	Instead of using C-like string literals (ie. "Alex") which are hard to work with,
	we can use the std::string and std::string_view types for our strings. These are NOT
	fundamental/primitive types and are CLASS types instead.

	std::string will use dma if the string object needs more space in memory at runtime.
	This can be slow.

BEST PRACTICES:

	- Do not pass std::string by value, as it makes an expensive copy.

*/

#include <iostream>
#include <string> // allows use of std::string

void stringLiteral()
{
	using namespace std::string_literals; // easy access to the s suffix

	std::cout << "foo\n";   // no suffix is a C-style string literal
	std::cout << "goo\n"s;  // s suffix is a std::string literal
}

// Use std::getline() to input text
void getLine()
{
	std::cout << "Pick 1 or 2: ";
	int choice{};
	std::cin >> choice;

	std::cout << "Now enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name); // read a full line of text from cin to name, note: added std::ws here

	std::cout << "Hello, " << name << ", you picked " << choice << '\n';
}

// std::string can handle strings of different lengths
void differentLengthStrings()
{
	std::string name{ "Alex" }; // initialize name with string literal "Alex"
	std::cout << name << '\n';

	name = "Jason";              // change name to a longer string
	std::cout << name << '\n';

	name = "Jay";                // change name to a shorter string
	std::cout << name << '\n';
}

int main()
{
	std::string name0{}; // empty string

	std::string name1{ "Alex" }; // initialize name with string literal "Alex"
	name1 = "John";               // change name to "John"



	return 0;
}