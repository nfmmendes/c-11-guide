#include <iostream>
#include <utility>
#include "string.h"
#include "utils.h"

using std::cout;
using std::endl;
using std::move;
using std::string;

int main()
{
    String *stringPointer = new String{"first"};
    String destinationString = move(*stringPointer); // Copy the address, but does not move the content.

    // The pointer is not null here.
    cout << *stringPointer << " | " << destinationString << endl;

    String stringVariable{"second"};
    destinationString = move(stringVariable);

    // The variable value is unknown (it can remain the same).
    cout << stringVariable << " | " << destinationString << endl;

    delete stringPointer;
    return 0;
}