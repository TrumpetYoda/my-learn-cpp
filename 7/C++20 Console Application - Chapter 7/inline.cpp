/*

Function calls take up resources. When a function is called, the CPU must store the return address, make space for new local variables, etc.

We can use inline functions to 'replace' the function call with the code that would be executed in its place instead.

This is known as 'inline expansion'.


For example, take these two functions:

    int min(int x, int y)
    {
        return (x < y) ? x : y;
    }

    int main()
    {
        std::cout << min(5, 6) << '\n';
        std::cout << min(3, 2) << '\n';
        return 0;
    }

Now with inline expansion, main would look like:

    int main()
    {
        std::cout << ((5 < 6) ? 5 : 6) << '\n';
        std::cout << ((3 < 2) ? 3 : 2) << '\n';
        return 0;
    }


This is a nice optimization, because we do not need to make a function call anymore, and 
    the compiler might do further optimizations in this case.

However, there might be cases where inline expansion actually causes larger executables (which slow down programs).

This is caused when the body of the function being expanded takes more instructions than the function call being replaced!

Therefor, inline expanison is BEST SUITED for simple, short functions, especially when the function call is being called 
    many times in short succession.


In modern C++ we actually do not manually define which functions should or should not be inline, the compiler handles that for us.

Instead, the term inline has evolved to mean “multiple definitions are allowed”. Thus, an inline function is 
    one that is allowed to be defined in multiple translation units (without violating the One Definition Rule (ODR)).

A RULE for the modern usage of inline functions:

    The compiler needs to be able to see the full definition of an inline function wherever it is used, and all 
        definitions for an inline function (with external linkage) must be identical (or undefined behavior will result).

Inline functions are typically defined in header files, where they can be #included into the top of any code file that 
    needs to see the full definition of the identifier. This ensures that all inline definitions for an identifier are identical.



BEST PRACTICE:

    Avoid the use of the inline keyword unless you have a specific, compelling reason to do so (e.g. you’re defining those 
        functions or variables in a header file).


BEST PRACTICE:

    If you need global constants and your compiler is C++17 capable, prefer defining inline constexpr global variables in a header file.
*/

/*

//pi.h file

#ifndef PI_H
#define PI_H

inline double pi() { return 3.14159; } // inline function defined in header file

#endif

*/

#include "pi.h" // will include a copy of pi() here
#include <iostream>

double circumference(double radius); // forward declaration

int main()
{
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}