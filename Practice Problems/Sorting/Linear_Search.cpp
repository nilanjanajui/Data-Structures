#include <iostream>
using namespace std;

int main()
{
    int DATA[11] = {8, 2, 5, 9, 1, 4, 7, 10, 3, 6};
    int n = 10, ITEM = 100, LOC;

    DATA[n + 1] = ITEM; // Adding sentinel
    LOC = 0;

    // Linear search with sentinel
    while (DATA[LOC] != ITEM)
    {
        LOC = LOC + 1;
    }

    // Check if ITEM is found within the list
    if (LOC == n + 1)
    {
        LOC = -1; // ITEM not found
    }

    // Output the result
    if (LOC == -1)
    {
        cout << "\nITEM is not in the List" << endl;
    }
    else
    {
        cout << "\nITEM found at Position " << LOC << endl;
    }

    return 0;
}
