#include <iostream>
#include <utility>
#include <vector>
#include <chrono>
#include "string.h"
#include "utils.h"

using std::cout;
using std::endl;
using std::move;
using std::vector;
using std::chrono::steady_clock;

// Bubble sort using only move
template <class T>
void sortByMove(vector<T> &vectorToBeSorted)
{
    if (vectorToBeSorted.size() == 0)
        return;

    T &&temporaryRvalue{T{}};
    for (int i = 0; i < vectorToBeSorted.size() - 1; i++)
        for (int j = i + 1; j < vectorToBeSorted.size(); j++)
        {
            if (vectorToBeSorted[j] < vectorToBeSorted[i])
            {
                temporaryRvalue = move(vectorToBeSorted[j]);
                vectorToBeSorted[j] = move(vectorToBeSorted[i]);
                vectorToBeSorted[i] = move(temporaryRvalue);
            }
        }
}

// Bubble sort using only copy
template <class T>
void sortByCopy(vector<T> &vectorToBeSorted)
{
    T temporaryLvalue;
    for (int i = 0; i < vectorToBeSorted.size() - 1; i++)
        for (int j = i + 1; j < vectorToBeSorted.size(); j++)
        {
            if (vectorToBeSorted[j] < vectorToBeSorted[i])
            {
                temporaryLvalue = vectorToBeSorted[j];
                vectorToBeSorted[j] = vectorToBeSorted[i];
                vectorToBeSorted[i] = temporaryLvalue;
            }
        }
}

template <class T>
void print(const vector<T> &inputVector)
{
    for (int i = 0; i < inputVector.size(); i++)
        cout << inputVector[i] << " ";
    cout << endl;
}

int main()
{
    // Sort a vector<int>
    vector<int> initialVector{13, 10, 24, 2, 8, 9, 4, 7, 15, 1, 18, 6};
    vector<int> vectorIntSortedByCopy{initialVector};
    vector<int> vectorIntSortedByMove{initialVector};

    cout << " -- Sorting a vector<int> -- \n\n";
    auto startSortByCopy{steady_clock::now()};
    sortByCopy(vectorIntSortedByCopy);
    auto endSortByCopy{steady_clock::now()};

    auto sortingByCopyDuration{endSortByCopy - startSortByCopy};
    cout << "Elapsed time to sort by copy: " << sortingByCopyDuration.count() << " nanoseconds." << endl;
    print(vectorIntSortedByCopy);

    auto startSortByMove{steady_clock::now()};
    sortByMove(vectorIntSortedByMove);
    auto endSortByMove{steady_clock::now()};

    auto sortingByMoveDuration{endSortByMove - startSortByMove};
    cout << "Elapsed time to sort by move: " << sortingByMoveDuration.count() << " nanoseconds." << endl;
    print(vectorIntSortedByMove);

    // Sort vector<string>
    vector<String> initialStringVector{"qwert", "wert", "erty", "rtyu", "tyui", "yuio", "uiop", "asdf", "sdfg", "dfgh", "fghj", "gjkl"};
    vector<String> vectorStringSortedByCopy(initialStringVector);
    vector<String> vectorStringSortedByMove(initialStringVector);

    cout << "\n\n -- Sorting a vector<string> -- \n\n";
    startSortByCopy = steady_clock::now();
    sortByCopy(vectorStringSortedByCopy);
    endSortByCopy = steady_clock::now();

    sortingByCopyDuration = endSortByCopy - startSortByCopy;
    cout << "Elapsed time to sort by copy: " << sortingByCopyDuration.count() << " nanoseconds." << endl;
    print(vectorStringSortedByCopy);

    startSortByMove = steady_clock::now();
    sortByMove(vectorStringSortedByMove);
    endSortByMove = steady_clock::now();

    sortingByMoveDuration = endSortByMove - startSortByMove;
    cout << "Elapsed time to sort by move: " << sortingByMoveDuration.count() << " nanoseconds." << endl;
    print(vectorStringSortedByMove);
}
