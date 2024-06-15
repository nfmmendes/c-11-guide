#include <memory>
#include <cassert>
using std::move;
using std::unique_ptr;

int main()
{
    unique_ptr<int> firstOwnerPointer(new int(6));

    // It does not compile.
    // std::unique_ptr<int> newOwnerPointer = firstOwnerPointer;

    // It compiles, but causes a double free error. Do not do it.
    // std::unique_ptr<int> newOwnerPointer(firstOwnerPointer.get());

    // The right way to transfer ownership.
    std::unique_ptr<int> newOwnerPointer = move(firstOwnerPointer);

    assert(firstOwnerPointer.get() == nullptr);

    return 0;
}
