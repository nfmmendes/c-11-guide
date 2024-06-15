#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

int main()
{
    const auto arraySize = 10;
    auto integerDeleter = [](int *pointer)
    {
        cout << "The pointer about to be deleted holds the value: " << *pointer << endl;
        delete pointer;
    };

    auto arrayDeleter = [arraySize](int *array)
    {
        cout << "The array about to be deleted holds the values : {";
        for (auto i{0}; i < arraySize; i++)
            cout << array[i] << (i < arraySize - 1 ? ", " : "}\n");

        delete[] array;
    };

    unique_ptr<int, decltype(integerDeleter)> pointerOwner(new int(6), integerDeleter);
    unique_ptr<int[], decltype(arrayDeleter)> arrayOwner(new int[]{1, 2, 3, 4, 5, 10, 9, 8, 7, 6}, arrayDeleter);

    return 0;
}
