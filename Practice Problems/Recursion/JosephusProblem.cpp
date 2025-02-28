#include <iostream>
using namespace std;


int Josephus(int n, int k)
{
    if (n == 1) 
    {
        return 0;
    }

    return (Josephus(n - 1, k) + k) % n;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int safePosition = Josephus(n, k) + 1;

    cout << "The safe position is: " << safePosition << endl;

    return 0;
}

