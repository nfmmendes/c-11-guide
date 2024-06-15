#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;

bool isPrime(int first)
{
    if (first == 2)
        return true;
    if (first % 2 == 0)
        return false;

    const auto squaredRoot = sqrt(first);
    for (int i = 3; i < sqrt(first); i += 2)
        if (first % i == 0)
            return false;

    return true;
}

template <class... Ts>
vector<bool> checkPrimes(Ts... sequence)
{
    return vector<bool>({isPrime(sequence)...});
}

int main()
{
    vector<bool> results = checkPrimes(3, 12, 5, 29, 2, 4, 15);

    cout << "{";
    for (auto i = 0; i < results.size(); i++)
        cout << results[i] << (i < results.size() - 1 ? " - " : "");
    cout << "}\n";

    return 0;
}