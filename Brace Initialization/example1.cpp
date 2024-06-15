#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::string;

int main()
{
    int integerValue{10};
    double doubleValue{5.05};
    string stringValue{"brace yourself"};
    bool booleanValue{true};

    int integerArray[]{5, 4, 3, 2, 1};
    int integerMatrix[][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int *nullPointer{};
    string emptyString{};
    bool undefinedBooleanValue{}; // expected to be false (not granted).
    bool undefinedIntValue{};     // expected to be zero (not granted).

    assert(integerValue == 10);
    assert(doubleValue == 5.05); // Safe comparison in this case.
    assert(stringValue == "brace yourself");
    assert(booleanValue == true);
    assert(nullPointer == nullPointer);
    assert(emptyString.size() == 0);

    return 0;
}