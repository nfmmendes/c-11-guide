#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;

int main()
{
    auto helloWord = []()
    { cout << "Hello world from lambda expression!" << endl; };
    function<void()> helloWorldFromFunction = []()
    { cout << "Hello world from function!" << endl; };

    helloWord();
    helloWorldFromFunction();

    return 0;
}
