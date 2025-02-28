#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i, J, N, K = 51, LA[101], ITEM = 106;

    // N = number of elements
    // K = position or index number
    // LA = array name
    // ITEM = element to be inserted

    N = 100;
    J = N;

    // Initialize array with random values
    for (i = 0; i < 100; i++)
    {
        LA[i] = rand() % 1000;
    }

    // Shift elements to make space for new ITEM
    while (J >= K)
    {
        LA[J + 1] = LA[J];
        J = J - 1;
    }

    LA[K] = ITEM; // Insert new element
    N = N + 1;    // Increase size of array

    cout << "ITEM " << LA[K] << " inserted at position " << K << endl;

    return 0;
}
