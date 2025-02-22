// 12
// https://vjudge.net/problem/CodeForces-1248B/origin

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; // assume the minimum is at index i

        // find the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j; // update the index of the minimum element
            }
        }

        // swap A[i] with A[min] if needed
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using Selection Sort
    selectionSort(arr, n);

    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; i++) {
        sum1 += arr[i];
    }
    for (int i = n / 2; i < n; i++) {
        sum2 += arr[i];
    }

    long long result = sum1 * sum1 + sum2 * sum2;
    cout << result << endl;
}

int main() {
    solve();
    return 0;
}
