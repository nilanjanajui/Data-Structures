#include <iostream>
#include<cmath>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];       // temporary array

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)         // if there is a remaining value
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)         // if there is a remaining value
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = floor((high + low) / 2);

        mergeSort(arr, low, mid);       // divided into middle
        mergeSort(arr, mid + 1, high);      // divided left and right side
        merge(arr, low, mid, high);      // call "merge" function for sorting
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {99, 6, 86, 15, 58, 35, 86, 4, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);    // '0' starting index, 'arr_size - 1' last index

    cout << "Sorted array: ";
    printArray(arr, arr_size);

    return 0;
}

