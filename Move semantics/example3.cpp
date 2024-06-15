#include <iostream>
#include <utility>
#include "utils.h"
#include "string.h"

using std::cout;
using std::endl;
using std::move;
using std::to_string;

String toString(int value)
{
    String returnedValue{to_string(value).c_str()};
    return returnedValue;
}

String getString()
{
    String nonConstantString{"Returned string"};
    // The code in the middle is not relevant.

    return nonConstantString;
}

int main()
{
    String nonConstantString{"Non constant string"};
    const String constString{"Constant string"};
    String *stringPointer = new String{"Non constant string pointer"};

    String constStringToBeReferenced{"Non const string to be referenced"};
    String &referenceToNonConstString = constStringToBeReferenced;

    char charArray[] = "This is a char array";

    String &&oldStyleInitializedRvalue = "Old style initialization";
    String &&braceInitializedRvalue{"Brace initialization"};
    String &&moveInitializedRvalue = move(nonConstantString);
    String &&referenceMoveInitializedRvalue = move(referenceToNonConstString);
    String &&stringPointerMoveInitializedRvalue = move(*stringPointer);
    String &&functionInitializedRvalue = toString(15);
    String &&userDefinedFunctionInitializedRvalue = getString();
    String &&charArrayInitializedRValue = charArray;

    /* These initializations do not compile.

    // It is not possible to pass a const to std::move() function
    string &&constStringMoveInitializedRValue = move(constString);

    // It is not possible to assign/bind a const lvalue to a rvalue reference
    string &&constStringInitializedRValue = constString;

    // It is not possible to assign/bind a lvalue reference to a rvalue reference
    string &&referenceInitializedRvalue = referenceToNonConstString;

    */

    cout << oldStyleInitializedRvalue << "\n"
         << braceInitializedRvalue << "\n"
         << moveInitializedRvalue << "\n"
         << stringPointerMoveInitializedRvalue << "\n"
         << referenceMoveInitializedRvalue << "\n"
         << functionInitializedRvalue << "\n"
         << userDefinedFunctionInitializedRvalue << "\n"
         << charArrayInitializedRValue << endl;

    cout << "\n\n -- Tracking moved-from lvalues -- \n";
    cout << "Non constant string: " << nonConstantString
         << "\nReference to non-const string: " << referenceToNonConstString
         << "\nString pointer: " << *stringPointer
         << "\nChar array: " << charArray << endl;

    delete stringPointer;

    return 0;
}