#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

int *getSmartPointerPointedElement()
{
    unique_ptr<int> smartPointer(new int(6));
    int *holder = smartPointer.get(); // Get handled memory address
    cout << "Memory with smart pointer alive: " << *holder << endl;

    return holder;
}

int main()
{
    int *holder = getSmartPointerPointedElement();
    cout << "Memory with smart pointer dead: " << *holder << endl;

    return 0;
}
