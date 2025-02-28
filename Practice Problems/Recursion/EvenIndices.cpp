#include <iostream>
#include <vector>
using namespace std;

void printEvenIndicesReversed(const vector<int> &arr, int N)
{

    for (int i = N - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << "Numbers at even indices in reversed order: ";
    printEvenIndicesReversed(arr, N);

    return 0;
}


