#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::find_if;
using std::sort;
using std::vector;

int main()
{
    // This is not a vector, but a std::initializer_list<int>.
    auto integerList = {12, 4, 31, 16, 19, 1};
    vector<int> integerVector(integerList);

    // This function does not build with a std::initializer_list<int> because the container
    // cannot be changed.
    sort(begin(integerVector), end(integerVector), [](int &first, int &second)
         { return first < second; });

    for (auto value : integerList)
        cout << "Current value: " << value << endl;

    // This function builds because std::find_if does not change the list.
    find_if(begin(integerList), end(integerList), [](int value)
            { return value == 19; });

    return 0;
}