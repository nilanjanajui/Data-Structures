#include <iostream>
using namespace std;

void printRecursion(int times)
{
    if (times == 0)
    {
        return;
    }
    cout << "I love Recursion" << endl;
    printRecursion(times - 1);
}

int main()
{
    int N;
    cout << "Enter the number of times to print: ";
    cin >> N;

    printRecursion(N);

    return 0;
}
