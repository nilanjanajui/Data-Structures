#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Traversing the linear array:" << endl;

    for (int i = 0; i < length; i++)
    {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }

    return 0;
}
