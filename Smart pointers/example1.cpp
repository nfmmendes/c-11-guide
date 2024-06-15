#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

int main()
{
    int *holder{};

    {
        unique_ptr<int> smartPointer(new int(6));
        holder = smartPointer.get(); // Get handled memory address
        cout << "Value with smart pointer alive: " << *holder << endl;
    };

    cout << "Value with smart pointer dead: " << *holder << endl;
    return 0;
}
