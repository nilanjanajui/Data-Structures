#include <iostream>

using namespace std;

int maxRegions(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return maxRegions(n - 1) + n;
}

int main()
{
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    cout << "Maximum number of regions: " << maxRegions(n) << endl;
    return 0;
}
