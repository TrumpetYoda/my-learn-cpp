/*

The constexpr keyword:

	- We can use this keyword to ensure we get compile-time constant variables.

	- A constexpr variable is always a compile-time constant. As a result, a constexpr 
	variable must be initialized with a constant expression, otherwise a compilation error will result.


	Additionally, constexpr works for variables with non-integral types:

		constexpr double d { 1.2 }; // d can be used in constant expressions!

BEST PRACTICE:

	- Any constant variable whose initializer is a constant expression should be declared as constexpr.

	- Any constant variable whose initializer is not a constant expression (making it a runtime constant) 
	should be declared as const.

	- Caveat: In the future we will discuss some types that are not fully compatible with constexpr (including std::string, 
	std::vector, and other types that use dynamic memory allocation). For constant objects of these types, either use const 
	instead of constexpr, or pick a different type that is constexpr compatible (e.g. std::string_view or std::array).

*/




#include <iostream>

// The return value of a non-constexpr function is not constexpr
int five()
{
	return 5;
}

int main()
{
	constexpr double gravity{ 9.8 }; // ok: 9.8 is a constant expression
	constexpr int sum{ 4 + 5 };      // ok: 4 + 5 is a constant expression
	constexpr int something{ sum };  // ok: sum is a constant expression

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	constexpr int myAge{ age };      // compile error: age is not a constant expression
	constexpr int f{ five() };       // compile error: return value of five() is not constexpr

	return 0;
}