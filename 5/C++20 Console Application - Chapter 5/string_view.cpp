/*

Introduction to std::string_view:

	- std::string_view is a class type for strings that provides read-only access to an existing string
	without making a copy.


BEST PRACTICE:

	- Prefer std::string_view over std::string when you need a read-only string, especially for 
	function parameters.

	- std::string_view is best used as a read-only function parameter

NOTE:
	
	- string is a (sole) owner, where string_view is a viewer type.

	- BE CAREFUL that the string being viewed does not get modified outside or destroyed while being used.

		- Modifying a std::string is likely to invalidate all views into that std::string.

		- If the views string does get modified, the viewers must be revalidated (set to some string) before being used again.

	- string_view may or may not be null terminated ('\0')


Should I prefer std::string_view or const std::string& function parameters?

	- Prefer std::string_view in most cases.


*/

#include <iostream>
#include <string>
#include <string_view> // C++17

// Assignment changes what the std::string_view is viewing
void assignmentExample()
{
	std::string name{ "Alex" };
	std::string_view sv{ name }; // sv is now viewing name
	std::cout << sv << '\n'; // prints Alex

	sv = "John"; // sv is now viewing "John" (does not change name)
	std::cout << sv << '\n'; // prints John

	std::cout << name << '\n'; // prints Alex
}

// std::string_view can be initialized with many different types of strings
void flexibilityExample()
{
	std::string_view s1{ "Hello, world!" }; // initialize with C-style string literal
	std::cout << s1 << '\n';

	std::string s{ "Hello, world!" };
	std::string_view s2{ s };  // initialize with std::string
	std::cout << s2 << '\n';

	std::string_view s3{ s2 }; // initialize with std::string_view
	std::cout << s3 << '\n';
}

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
	std::cout << str << '\n';
}

int main()
{
	std::string_view s{ "Hello, world!" }; // now a std::string_view
	printSV(s);

	return 0;
}