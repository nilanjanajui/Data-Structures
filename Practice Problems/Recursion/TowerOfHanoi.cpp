#include <iostream>
#include <cmath>

using namespace std;


void TowerOfHanoi(int n, int from, int to, int temp)
{
    if (n == 0)
    {
        return;
    }

    TowerOfHanoi(n - 1, from, temp, to);

    cout << from << " " << to << endl;

    TowerOfHanoi(n - 1, temp, to, from);
}

int main()
{
    int n;

    cout << "Number of disks: " << endl;
    cin >> n;

    cout << "Number of moves: " << endl;
    cout << ((pow(2, n)) - 1) << endl;

    cout << "Moving disks " << endl;
    TowerOfHanoi(n, 1, 3, 2);

    return 0;
}

