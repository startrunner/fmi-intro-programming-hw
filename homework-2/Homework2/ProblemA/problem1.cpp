#include <iostream>
#include <cinttypes>
#include <cstdio>
using namespace std;

bool tryRemoveSuffix(unsigned *number, unsigned suffix)
{
    if (suffix > *number)return false;

    unsigned numberState = *number;
    bool success = true;

    do
    {
        success &= (numberState % 10 == suffix % 10);
        numberState /= 10;
        suffix /= 10;
    } while (suffix != 0 && success);

    if (success)*number = numberState;
    return success;
}

bool checkIsRepeating(unsigned candidate, unsigned repeated)
{
    bool isRepeating = true;

    do
    {
        isRepeating &= tryRemoveSuffix(&candidate, repeated);
    } while (candidate != 0 && isRepeating);

    return isRepeating;
}

bool allRepeatedNumbers(unsigned int numbers[], unsigned int length)
{
    bool allAreRepeated = true;
    for (unsigned i = 0; i < length && allAreRepeated; i++)
    {
        allAreRepeated &= checkIsRepeating(numbers[i], i);
    }
    return allAreRepeated;
}