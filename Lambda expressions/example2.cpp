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

    auto printCustomPhrase = [](const char *phrase)
    {
        cout << phrase << endl;
    };

    function<void(const char *)> printCustomPhraseFromFunction = [](const char *phrase)
    { cout << phrase << endl; };

    printCustomPhrase("This is a custom phrase!");
    printCustomPhraseFromFunction("This is a custom phase from function!");

    return 0;
}