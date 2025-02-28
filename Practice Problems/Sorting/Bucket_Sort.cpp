#include <iostream>
using namespace std;

void insertionSort(int bucket[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(int arr[], int n)
{

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // Number of buckets (Choosing bucket count as maxVal / 5 + 1)
    int bucketCount = maxVal / 5 + 1;
    int buckets[bucketCount][n];       
    int bucketSize[bucketCount] = {0}; 


    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / 5;                             
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < bucketCount; i++)
    {
        if (bucketSize[i] > 0)
        {
            insertionSort(buckets[i], bucketSize[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < bucketSize[i]; j++)
        {
            arr[index++] = buckets[i][j];
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
    int arr[] = {11, 9, 21, 8, 17, 19, 13, 1, 24, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

