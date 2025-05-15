#include <iostream>

// internal linkage is done with the static keyword
static int g_x{ 3 }; // this separate internal g_x is only accessible within linkage_example.cpp

// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
static int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << g_x << '\n'; // uses main.cpp's g_x, prints 3

    return 0;
}


// Essentially, the 'static' keyword restricts things to internal linkage, which only allows 
//  references to static data within the file it was declared in. 'const' also only has internal
//  linkage.