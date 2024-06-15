#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <class T>
void printStdContainer(const T &container)
{
    for (int i = 0; i < container.size(); i++)
        cout << container[i] << " ";
    cout << endl;
}

int main()
{
    string stringByCharList{'s', 't', 'r', 'a', 'n', 'g', 'e', ' ', 'l', 'i', 's', 't'};
    vector<string> stringVector{"this", "is", "a", "string", "list"};
    vector<int> vectorInitSpecialCase(5, 10);
    vector<int> twoValuesVectorInit{5, 10};

    cout << stringByCharList << endl;

    printStdContainer(stringVector);
    printStdContainer(vectorInitSpecialCase);
    printStdContainer(twoValuesVectorInit);

    return 0;
}