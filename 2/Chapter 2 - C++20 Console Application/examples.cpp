#define NAME "Alex" // Object-like macros with substitution text is no longer necessary (unlike C)

// Object-like macro without substitution text:
//		- Generally acceptable to use.
//		- used with #ifdef and #ifndef to specify what sections of code will or wont be compiled
//			based on if a macro is defined or not.
#define USE_YEN 

#include <iostream>

void ifZeroExample()
{
#if 0 // Don't compile anything starting here. 1 would be always true (always compile).

	std::cout << "Bob\n";
	std::cout << "Steve\n";

#endif // until this point
}

void printCurrency()
{
#ifdef USE_YEN

	std::cout << "Using yen...\n";

#endif

#ifdef USE_USD

	std::cout << "Using usd...\n";

#endif
}


// functions example

//void doSomething1(int count) // warning: unreferenced parameter count
//{
//	// This function used to do something with count but it is not used any longer
//}


void doSomething2(int /*count*/) // ok: unnamed parameter will not generate warning
{
	// ^^^ The Google C++ style guide recommends using a comment to document what the unnamed parameter was ^^^
	// https://stackoverflow.com/questions/12186698/why-does-c-allow-unnamed-function-parameters
}


int getValueFromUser()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value)
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

//int main()
//{
//	printDouble(getValueFromUser());
//
//	return 0;
//}