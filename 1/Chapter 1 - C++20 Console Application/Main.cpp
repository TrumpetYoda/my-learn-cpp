#include <iostream>

// Only skimmed through a lot of the content on this 
//	chapter as a lot applies to C which I know well 
//	enough to understand those concepts.

int inititalization_example()
{
	// Copy-initialization
	/*
	*	Copy-initialization had fallen out of favor in modern C++ due to being
		less efficient than other forms of initialization for some complex types.
	*/
	int a = 5;

	

	// Direct-initialization
	/*
	*	Direct-initialization was initially introduced to allow for more efficient
		initialization of complex objects (those with class types, which we’ll cover in a
		future chapter). Just like copy-initialization, direct-initialization had fallen
		out of favor in modern C++, largely due to being superseded by direct-list-initialization.
	*/
	int b(5);

	
	// List-initialization
	/*	The modern way to initialize objects in C++ is to use a form of initialization that makes 
		use of curly braces. This is called list-initialization (or uniform initialization 
		or brace initialization).
	*/
	// Two forms:
	int c{ 5 }; // direct-list-initialization of initial value 5 into variable width (preferred)
	int d = { 5 }; // copy-list-initialization of initial value 6 into variable height (rarely used)

	// List-Initialization disallows narrowing conversions:
	/*
		One of the primary benefits of list-initialization for new C++ programmers is that 
		“narrowing conversions” are disallowed. This means that if you try to list-initialize a 
		variable using a value that the variable can not safely hold, the compiler is required to 
		produce a diagnostic (compilation error or warning) to notify you.
	*/
	// For Example:

	// An integer can only hold non-fractional values.
	// Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
	// Such a conversion is a narrowing conversion, since the fractional part of the value will be lost.

	int w1{ 4.5 }; // compile error: list-init does not allow narrowing conversion

	int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
	int w3(4.5);   // compiles: w3 direct-initialized to value 4


	// Zero-initialization with list-initialization 

	int width{}; // value-initialization / zero-initialization to value 0


	// LIST-INITIALIZATION IS THE PREFERRED FORM OF INITIALIZATION IN MODERN C++ 
	
	// Best practice:
	//		Prefer direct - list - initialization or value - initialization to initialize your variables.


	return 0;
}

int main()
{
	return 0;
}