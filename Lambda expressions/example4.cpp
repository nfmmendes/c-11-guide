#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
    auto cost = 50;

    auto evaluateSum = [=](int quantity)
    {
        return cost * quantity;
    };

    auto evaluateRemains = [=](int quantity, int total = 2000)
    {
        return total - cost * quantity;
    };

    auto quantities = {10, 20, 3, 18, 9};
    for (auto quantity : quantities)
        cout << "Cost to buy " << quantity << " units: " << evaluateSum(quantity) << endl;

    for (auto quantity : quantities)
        cout << "Remanining after buying " << quantity << " units: " << evaluateRemains(quantity) << endl;

    return 0;
}