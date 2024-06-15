#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
using std::make_pair;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
    // It does not compile without a '=' operator.
    auto integerList = {2, 4, 3, 6, 9, 10};

    // This is initialized as a list initialized, not a pair.
    auto twoElementsIntegerList = {2, 4};

    // Initialize vector with list initializer.
    auto integerVector{static_cast<vector<int>>(integerList)};

    // Initialize with make_pair as list initializer is not possible.
    auto mixedPair = make_pair("value", 4);

    // Without the cast the compiler deduces a const char*
    auto autoString = string("test string");

    return 0;
}