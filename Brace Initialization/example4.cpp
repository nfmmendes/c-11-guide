#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::string;

struct SimpleStruct
{
    int integer;
    double real;
    string label;
};

int main()
{
    char someCharArray[] = "Char array";
    SimpleStruct simpleStructValues{5, 3.9, "test"};

    // Casting char[] to string is valid. Casting double to int is not.
    SimpleStruct implicitCastStructValues{5, 2, someCharArray};

    // Builds without problems.
    SimpleStruct explicitCastStructValues{int(5.2), 2, someCharArray};

    assert(implicitCastStructValues.integer == explicitCastStructValues.integer);
    assert(simpleStructValues.label == "test");

    return 0;
}