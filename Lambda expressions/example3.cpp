#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::string;

void runLambda(function<void()> &&lambda)
{
    lambda();
}

void runOneStringParamLambda(string param, function<void(const string &)> &&lambda)
{
    lambda(param);
}

int main()
{
    auto helloWord = []()
    { cout << "Hello world from lambda expression!" << endl; };

    auto customPhrase = [](const string &customPhrase)
    { cout << customPhrase << endl; };

    runLambda(helloWord);
    runOneStringParamLambda("A custom phrase", customPhrase);

    return 0;
}