// 31
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] > A[maxIndex]) {  // Change comparison to descending order
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(A[i], A[maxIndex]);
        }
    }
}

int findKthLargest(int A[], int n, int k) {
    selectionSort(A, n);  // Sort the array in descending order
    return A[k - 1];  // Return the kth largest element
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Enter k: ";
    cin >> k;

    int result = findKthLargest(A, n, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
