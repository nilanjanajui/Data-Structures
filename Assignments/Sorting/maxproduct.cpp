// 32
// https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <iostream>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

int maximumProduct(int A[], int n) {
    selectionSort(A, n); // Sort the array

    // Calculate the maximum product
    return max(A[n-1] * A[n-2] * A[n-3], A[0] * A[1] * A[n-1]);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = maximumProduct(A, n);
    cout << "The maximum product of three numbers is: " << result << endl;

    return 0;
}
