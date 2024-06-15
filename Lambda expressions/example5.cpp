#include <iostream>
#include <utility>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::move;
using std::string;

function<int(int)> getEvaluationFunction()
{
    auto cost = 50;
    // Using a capture by reference is an error. The value must be captured by value.
    auto evaluateSum = [&](int quantity)
    {
        return cost * quantity;
    };

    return evaluateSum;
}

void runLambda(function<void(const string &)> lambda, const string &value)
{
    lambda(value);
}

int main()
{
    auto evaluationFunction = getEvaluationFunction();
    auto quantities = {10, 20, 3, 18, 9};
    for (auto quantity : quantities)
        cout << "Cost to buy " << quantity << " units: " << evaluationFunction(quantity) << endl;

    string customString = "This is a custom string.";
    auto printCustomString = [&](const string &complement)
    {
        cout << customString << " " << complement << endl;
    };

    runLambda(printCustomString, " And this is the complement");

    return 0;
}