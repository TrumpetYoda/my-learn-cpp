/*
Best practice:

To maximize the chance that missing includes will be flagged by compiler, ORDER your #includes 
    as follows (skipping any that are not relevant):

    1. The paired header file for this code file (e.g. add.cpp should #include "add.h")
    2. Other headers from the same project (e.g. #include "mymath.h")
    3. 3rd party library headers (e.g. #include <boost/tuple/tuple.hpp>)
    4. Standard library headers (e.g. #include <iostream>)

The headers for each grouping should be sorted alphabetically (unless the documentation for a 
    3rd party library instructs you to do otherwise).
*/



#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}