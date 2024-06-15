#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <type_traits>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int nonConstInt{5};
    int &intReference{nonConstInt};
    const int constInt{6};
    volatile int volatileInt{7};
    vector<bool> booleanVector{false, false, true, false};

    auto missedReference = intReference;
    auto missedConstantness = constInt;
    auto missedVolatileness = volatileInt;
    auto isReferenceButNotBool = booleanVector[2]; // proxy types requires cast.

    // builds because the type deduced is int instead of const int.
    missedConstantness = 10;

    // Requires #include <type_traits>
    cout << "missedReference is a reference? " << std::is_reference<decltype(missedReference)>::value << endl;
    cout << "missedVolatileness is volatile? " << std::is_volatile<decltype(missedVolatileness)>::value << endl;

    // The types are not the same.
    assert(strcmp(typeid(isReferenceButNotBool).name(), typeid(false).name()) != 0);

    return 0;
}