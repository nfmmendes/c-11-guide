#include <iostream>
#include <string>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::string;

int main()
{
    // This is not a vector, but a std::initializer_list<int>.
    auto integerList = {2, 4, 3, 6, 9, 10};

    for (auto value : integerList)
        cout << "Current value: " << value << endl;

    map<string, int> autoMap{make_pair("1st", 1), make_pair("2nd", 4),
                             make_pair("3rd", 3)};

    // With C++17 is possible to use a structured bind,
    // i.e: for(auto [key, value] : simpleMap){...}.
    cout << "Loop without accessing iterators\n";
    for (auto &item : autoMap)
        cout << "Key: " << item.first << ", value: " << item.second << endl;

    cout << "Loop accessing iterators\n";
    for (auto it = begin(autoMap); it != end(autoMap); it++)
        cout << "Key: " << it->first << ", value: " << it->second << endl;

    return 0;
}