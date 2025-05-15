#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed ONCE.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}

/*

s_value remembers its value because it has static duration rather than local duration.

It IS inacessible once out of the local scope, but remains in memory and can be 
    accessed again once we get back to that scope.

KEY INSIGHT:

    Static local variables are best used to avoid expensive local object initialization 
        each time a function is called.

BEST PRACTICE:
    
    Const static local variables are generally okay to use.

    Non-const static local variables should generally be avoided. If you do use them, ensure the 
        variable never needs to be reset, and isn’t used to alter program flow.



Output:

    2
    3
    4

*/