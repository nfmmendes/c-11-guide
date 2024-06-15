#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <cassert>
using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::string;
using std::vector;

int main()
{
    auto integerSharedPointer = make_shared<int>(10);
    auto stringSharedPointer = make_shared<string>("test");
    auto pairSharedPointer = make_shared<pair<int, string>>(10, "test");
    auto vectorSharedPointer = make_shared<vector<int>>(vector<int>({10, 15, 20, 30}));

    assert(*integerSharedPointer == 10);
    assert(*stringSharedPointer == "test");
    assert((*pairSharedPointer).second == *stringSharedPointer);
    assert((*vectorSharedPointer).size() == 4);

    return 0;
}