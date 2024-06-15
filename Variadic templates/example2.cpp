#include <iostream>
using std::cout;

template <class T>
int sum(T value)
{
    return value;
}

template <class T, class... Ts>
int sum(int initialValue, T first, Ts... values)
{
    return sum(initialValue + first, values...);
}

int main()
{
    cout << "The total is: " << sum(1, 2, 3, 4, 5, 6) << "\n";

    // Does not build because the first parameter must be an integer.
    // cout << sum("fail", 3, 4, 6, 2, 8);

    // Does not build because the all packed parameters must be integers.
    // cout << sum(1, 3, 4, 6, 2, "fail");

    return 0;
}