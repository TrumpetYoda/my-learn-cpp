#include <iostream>

/*

References work conceptually as aliases. The compiler might even optimize out references 
entirely if it can and just replace them with what they are referencing.

Example:

    int x{};
    int& ref{x};

    ref = 5; // this would be the same as saying x = 5;
*/

void refExample1()
{
    int x{ 5 };    // x is a normal integer variable
    int& ref{ x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)
}

void refExample2()
{
    int x{ 5 }; // normal integer variable
    int& ref{ x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77
}

void refInitialization()
{
    //int& invalidRef;   // error: references must be initialized

    int x{ 5 };
    int& ref{ x }; // okay: reference to int is bound to int 
}

void refCannotBeReseated()
{
    int x{ 5 };
    int y{ 6 };

    int& ref{ x }; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5
}