/*

Debugging Tips:

	- When validating flow via printing to the console, use 'std::cerr' rather than 'std::cout'.
		This is because 'str::cerr' is unbuffered, and will go out to the console right when instruction is executed.

*/

#include <iostream>

void printValue(int value)
{
    std::cout << value << '\n';
}

int main()
{
    printValue(5);

    return 0;
}