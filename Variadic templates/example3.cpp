#include <iostream>
#include <set>
#include <vector>
using std::cout;
using std::endl;
using std::set;
using std::vector;

template <class T, class... Ts>
void printOrderedDistinct(T first, Ts... values)
{
    set<T> setOfValues = {first, values...};

    cout << "Ordered and distinct values: \n";
    for (auto item : setOfValues)
        cout << item << " ";
    cout << endl;
}

template <class... Ts>
void printFreeDays(Ts... values)
{
    vector<int> freeDays{1, values..., 7};

    cout << "The free days are: \n";
    for (auto item : freeDays)
        cout << item << " ";
    cout << endl;
}

int main()
{
    printOrderedDistinct(9, 4, 1, 2, 2, 9, 10, 3, 9, 1, 8);
    printFreeDays(3, 5);
    printFreeDays(2, 4, 6);

    return 0;
}