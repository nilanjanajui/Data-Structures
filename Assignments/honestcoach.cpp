// 14
// https://codeforces.com/contest/1360/problem/B

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Selection Sort implementation
void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // Assume the minimum is at index i

        // Find the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;  // Update the index of the minimum element
            }
        }

        // Swap A[i] with A[min] if needed
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> strengths(n);

    // Input the strengths
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    // Convert the vector to an array for selection sort
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = strengths[i];
    }

    // Sort the array using Selection Sort
    selectionSort(arr, n);

    // Find the minimum difference between consecutive athletes
    int min_diff = INT_MAX;
    for (int i = 1; i < n; i++) {
        min_diff = min(min_diff, arr[i] - arr[i - 1]);
    }

    // Output the result for the current test case
    cout << min_diff << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
