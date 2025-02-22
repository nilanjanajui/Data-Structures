// 36
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2457

#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& A, int k, int n) {
    // Initialize the count array
    vector<int> C(k + 1, 0);
    vector<int> B(n);  // Output array

    // Count occurrences of each element
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Calculate positions of elements
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // Build the output array in sorted order
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    // Copy the sorted array back to A
    A = B;  
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> ages(n);
        int maxAge = 0;

        // Input the ages
        for (int i = 0; i < n; i++) {
            cin >> ages[i];
            maxAge = max(maxAge, ages[i]);
        }

        // Use counting sort to sort the ages
        countingSort(ages, maxAge, n);

        // Output the sorted ages
        for (int i = 0; i < n; i++) {
            cout << ages[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
