// why ref type is useful


#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

void passByRefExample()
{
    std::string x{ "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)
}