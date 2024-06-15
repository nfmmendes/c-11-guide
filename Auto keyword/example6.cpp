#include <iostream>
using std::cout;
using std::endl;

template <class T, class U>
auto exoticMaxFunction(T first, U second) -> decltype(first)
{
    return first > second ? first : second;
}

int main()
{
    int intValue = 6;
    double doubleValue = 3.2;
    char charValue = 'a';

    auto firstResult = exoticMaxFunction(intValue, doubleValue);
    auto secondResult = exoticMaxFunction(charValue, doubleValue);

    cout << typeid(firstResult).name() << " " << typeid(secondResult).name() << endl;

    return 0;
}