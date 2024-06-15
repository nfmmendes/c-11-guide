#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void printValues()
{
    cout << endl;
}

template <class T, class... Ts>
void printValues(T first, Ts... slices)
{
    cout << first;
    printValues(slices...);
}

int main()
{
    printValues("Hello ", "world ", " using ", "packed ", "params.");
    return 0;
}