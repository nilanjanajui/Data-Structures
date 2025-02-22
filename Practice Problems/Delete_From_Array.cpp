#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i, J, N, K = 51, LA[101];

    N = 100;

    for (i = 0; i < N; i++)
    {
        LA[i] = rand() % 1000;
    }

    cout << "Before Deletion:\n";
    for (i = 0; i < N; i++)
    {
        cout << LA[i] << " ";
    }
    cout << endl;

    int ITEM = LA[K]; 
    J = K;

    while (J < N - 1)
    {
        LA[J] = LA[J + 1];
        J = J + 1;
    }

    N = N - 1;

    cout << "\nITEM " << ITEM << " deleted from position " << K << endl;

    cout << "\nAfter Deletion:\n";
    for (i = 0; i < N; i++)
    {
        cout << LA[i] << " ";
    }
    cout << endl;

    return 0;
}
