#include <iostream>
#include <type_traits> // for std::common_type_t

template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>; // returns the common type of T and U

int main()
{
    std::cout << max(2, 3.5) << '\n';

    return 0;
}

template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>
{
    return (x < y) ? y : x;
}