#include <iostream>
#include <memory>
#include <cassert>
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

int main()
{
    auto sharedPointer = make_shared<int>(10);
    auto coOwnerPointer = sharedPointer;

    cout << "Sharing pointers: " << sharedPointer.use_count() << endl;

    {
        weak_ptr<int> weakPointer{sharedPointer};

        {
            weak_ptr<int> coWeakPointer{sharedPointer};
            weak_ptr<int> secondCoWeakPointers{sharedPointer};
            assert(sharedPointer.use_count() == 2);
        }

        assert(weakPointer.use_count() == 2);
    }

    assert(sharedPointer.use_count() == 2);

    return 0;
}