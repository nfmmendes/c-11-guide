#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <cassert>
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

void releaseSharedPointer(shared_ptr<int> &pointer)
{
    cout << "This shared pointer points to: " << pointer.get();
    cout << " and is shared with other " << pointer.use_count() - 1 << " shared_ptr's\n";

    // Release ownership but does not delete the memory block if it is shard with other smart pointer.
    pointer.reset();

    cout << "This shared pointer points to: " << pointer.get();
    cout << " and " << pointer.use_count() << " shared_ptr's shares this memory block\n";
}

int main()
{
    auto sharedPointer = make_shared<int>(10);
    auto coOwner = sharedPointer;

    weak_ptr<int> weakPointer(sharedPointer);

    releaseSharedPointer(sharedPointer);

    // Check if the memory block pointed by the shared pointer still exists,
    assert(!weakPointer.expired());
    assert(coOwner.use_count() == 1);

    releaseSharedPointer(coOwner);

    assert(weakPointer.expired());
    assert(coOwner.use_count() == 0);

    return 0;
}