#include <iostream>

namespace Foo
{
	namespace Goo // Goo is a namespace inside the Foo namespace
	{
		int add(int x, int y)
		{
			return x + y;
		}
	}
}

// nested namespaces can also be declared like: 
//		'namespace Foo::Goo' // Goo is a namespace inside the Foo namespace (C++17 style)

int main()
{
	std::cout << Foo::Goo::add(1, 2) << '\n';
	return 0;
}