#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::string;

int main()
{
    int *nullPointer{};
    string emptyString{};
    bool undefinedBooleanValue{}; // expected to be false (not granted).
    bool undefinedIntValue{};     // expected to be zero (not granted).

    assert(nullPointer == nullPointer);
    assert(emptyString.size() == 0);

    cout << "Undefined bool with value " << undefinedBooleanValue << endl;
    cout << "Undefined integer with value : " << undefinedIntValue << endl;

    return 0;
}