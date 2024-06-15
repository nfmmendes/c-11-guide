#include <iostream>
#include <utility>
#include "utils.h"
#include "string.h"

using std::cout;
using std::endl;
using std::move;

int main()
{
    String first{"first"};
    String second{"second"};

    // Original variable values.
    cout << first << " | " << second << endl;

    String temp = move(first);
    first = move(second);
    second = move(temp);

    // Variables values after swap.
    cout << first << " | " << second << endl;

    temp = move(first);
    second = temp;

    // First value missing after move.
    cout << first << " | " << second << endl;

    return 0;
}