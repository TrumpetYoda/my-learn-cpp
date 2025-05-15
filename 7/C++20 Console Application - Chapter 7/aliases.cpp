#include <iostream>

namespace Foo::Goo
{
	int add(int x, int y)
	{
		return x + y;
	}
}

int main()
{
	namespace Active = Foo::Goo; // active now refers to Foo::Goo

	std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

	return 0;
} // The Active alias ends here

/*

One nice advantage of namespace aliases: If you ever want to move the functionality within Foo::Goo to 
a different place, you can just update the Active alias to reflect the new destination, rather than 
having to find/replace every instance of Foo::Goo.

*/