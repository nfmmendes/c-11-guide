#include <iostream>
#include <utility>
#include <vector>
#include <chrono>
#include "string.h"
#include "utils.h"

using std::cout;
using std::endl;
using std::move;

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

// Function declared with universal reference.
template <class T>
void fowardFunction(T &&param)
{
    printReference(param);
}

int main()
{
    String nonConstantString{"Non constant string"};
    const String constString{"Constant string"};
    String *stringPointer = new String{"Non constant string pointer"};

    String constStringToBeReferenced{"Non const string to be referenced"};
    String &referenceToNonConstString = constStringToBeReferenced;

    cout << "Tracking rvalue strings\n\n";
    fowardFunction("Literal string");
    fowardFunction(String{"Literal string inside braces"});
    fowardFunction(String{"Concateneted string "} + String{" initialization"});
    fowardFunction(move(nonConstantString));
    fowardFunction(move(referenceToNonConstString));
    fowardFunction(move(*stringPointer));

    cout << "\n\n Tracking lvalue strings\n\n";
    fowardFunction(nonConstantString);
    fowardFunction(constString);
    fowardFunction(referenceToNonConstString);

    delete stringPointer;

    return 0;
}