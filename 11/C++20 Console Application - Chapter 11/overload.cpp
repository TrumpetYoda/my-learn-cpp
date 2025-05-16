#include <iostream>

int add(int x, int y)
{
	std::cout << "add with ints used\n";
	return x + y;
}

double add(double x, double y)
{
	std::cout << "add with doubles used\n";
	return x + y;
}

int main()
{
	std::cout << add(5, 4) << "\n";
	std::cout << add(2.3, 4.5) << "\n";

	return 0;
}