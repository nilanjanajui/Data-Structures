#include <iostream>
using namespace std;

void Weird(int n)
{
    cout << n << " ";

    if (n == 1)
    {
        return;
    }

    if (n % 2 == 0)
    {
        Weird(n / 2);
    }
    else
    {
        Weird(3 * n + 1);
    }
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "The sequence: ";
    Weird(n);

    return 0;
}
