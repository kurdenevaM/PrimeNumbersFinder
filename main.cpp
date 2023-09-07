#include <iostream>
#include <math.h>

using namespace std;

void findPrimeNumbers(unsigned int* primeNumbers, int primeNumberCount)
{
    int foundPrimeNumberCount = 0;
    unsigned int actualNumber = 2;
    primeNumbers[foundPrimeNumberCount] = actualNumber;
    foundPrimeNumberCount++;
    actualNumber++;
    bool isPrime;

    for (; foundPrimeNumberCount < primeNumberCount; actualNumber += 2)
    {
        isPrime = true;
        for(int i = 1; i < foundPrimeNumberCount; i++)
        {
            if (primeNumbers[i] > sqrt(actualNumber))
                break;
            if (actualNumber%primeNumbers[i] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primeNumbers[foundPrimeNumberCount] = actualNumber;
            foundPrimeNumberCount++;
        }
    }
}

void printNumberArray(unsigned int* numberArray, int count)
{
    for (int i = 0; i < count; i++)
        cout << numberArray[i] << "    ";
}

int main()
{
    int primeNumberCount = 0;
    cout << "How many prime numbers do you want to display?" << endl;
    cin >> primeNumberCount;
    unsigned int* primeNumbers = new unsigned int[primeNumberCount];
    findPrimeNumbers(primeNumbers, primeNumberCount);
    cout << "Prime numbers:" << endl;
    printNumberArray(primeNumbers, primeNumberCount);
    delete[] primeNumbers;
    return 0;
}
