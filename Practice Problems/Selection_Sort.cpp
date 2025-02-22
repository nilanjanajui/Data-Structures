// For descending Order

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)      // for swapping
        {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array (Descending Order): ";
    printArray(arr, n);

    return 0;
}

// For ascending order

// #include <iostream>
// using namespace std;

// void selectionSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int maxIndex = i;

//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[maxIndex])
//             {
//                 maxIndex = j;
//             }
//         }

//         if (maxIndex != i)
//         {
//             int temp = arr[i];
//             arr[i] = arr[maxIndex];
//             arr[maxIndex] = temp;
//         }
//     }
// }

// void printArray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int arr[] = {77, 33, 44, 11, 88, 22, 66, 55};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, n);

//     selectionSort(arr, n);

//     cout << "Sorted array (Ascending Order): ";
//     printArray(arr, n);

//     return 0;
// }
