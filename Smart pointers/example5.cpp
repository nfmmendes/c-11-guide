#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

int main()
{
    shared_ptr<int> firstSharedPointer(new int(5), [](int *p)
                                       {   cout << "Delete value: " << *p << endl;
                                                delete p; });
    cout << "Pointers sharing the memory: " << firstSharedPointer.use_count() << endl;

    shared_ptr<int> secondSharedPointer(firstSharedPointer);
    cout << "Pointers sharing the memory: " << firstSharedPointer.use_count() << endl;

    shared_ptr<int> thirdSharedPointer{firstSharedPointer};
    cout << "Pointers sharing the memory: " << firstSharedPointer.use_count() << endl;

    {
        shared_ptr<int> fourthSharedPointer = secondSharedPointer;
        cout << "Pointers sharing the memory: " << firstSharedPointer.use_count() << endl;
    }
    cout << "Pointers sharing the memory: " << firstSharedPointer.use_count() << endl;

    return 0;
}