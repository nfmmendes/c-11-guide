#include <iostream>
#include <utility>
#include "utils.h"
#include "string.h"

using std::cout;
using std::endl;
using std::move;
using std::to_string;

namespace
{
    const String stringToBeReferenced{"constant string on namespace"};
}

String toString(int value)
{
    String returnedValue{to_string(value).c_str()};
    return returnedValue;
}

// All functions print the string passed, but each one specifies if it is understood
// as a rvalue reference or a lvalue (const or non const) reference.
void printReference(String &&value)
{
    cout << "The string \"" << value << "\" is received as a rvalue. \n";
}

void printReference(const String &value)
{
    cout << "The string \"" << value << "\" is received as a const lvalue reference. \n";
}

void printReference(String &value)
{
    cout << "The string \"" << value << "\" is received as a non-const lvalue reference. \n";
}

String getString()
{
    String nonConstantString{"Returned string"};
    // The code in the middle is not relevant.

    return nonConstantString;
}

const String &getStringReference()
{
    return stringToBeReferenced;
}

int main()
{
    String nonConstantString{"Non constant string"};
    const String constString{"Constant string"};
    String *stringPointer = new String{"Non constant string pointer"};

    String constStringToBeReferenced{"Non const string to be referenced"};
    String &referenceToNonConstString = constStringToBeReferenced;

    char charArray[] = "This is a char array";

    cout << "Tracking rvalue strings\n\n";
    printReference("Literal string");
    printReference({"Literal string inside braces"});
    printReference(String{"Concateneted string "} + String{"initialization"});
    printReference(move(nonConstantString));
    printReference(move(referenceToNonConstString));
    printReference(move(*stringPointer));
    printReference(toString(15));
    printReference(getString());
    printReference(charArray);
    printReference(move(charArray));

    cout << "\n\n Tracking lvalue strings\n\n";
    printReference(nonConstantString);
    printReference(constString);
    printReference(referenceToNonConstString);
    printReference(getStringReference());

    delete stringPointer;

    return 0;
}