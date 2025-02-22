#include <iostream>
using namespace std;

void CountingSort(int A[], int n)
{
    // Find the maximum element (k) to define the size of count array
    int k = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > k)
        {
            k = A[i];
        }
    }

    // Initialize count array C with zeros
    int C[k + 1]; // Count array from 0 to k
    int B[n];     // Output array

    // Initialize C to 0
    for (int i = 0; i <= k; i++)
    {
        C[i] = 0;
    }

    // Store the count of each element in A
    for (int j = 0; j < n; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }

    // Change C[i] to contain the actual position of elements in output array
    for (int i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    // Build the output array B from C
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {2, 4, 1, 2, 8, 6, 3, 8, 5, 7};
    int n = sizeof(A) / sizeof(A[0]);

    CountingSort(A, n);

    return 0;
}
