#include <iostream>
using std::cout;
using std::endl;

class HelloWorldPrint
{
public:
    void operator()()
    {
        cout << "Hello world from class function!" << endl;
    }
};

int main()
{
    auto helloWord = []()
    { cout << "Hello world from lambda expression!" << endl; };

    helloWord();

    HelloWorldPrint helloWorldObject;
    helloWorldObject();

    return 0;
}