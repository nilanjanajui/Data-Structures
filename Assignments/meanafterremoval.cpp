// 33
// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void countingSort(vector<int>& A, int k, int n) {
    vector<int> C(k + 1, 0);
    vector<int> B(n);  // Output array

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    A = B;  // Copy sorted elements back to A
}

double trimMean(vector<int>& arr) {
    int n = arr.size();
    int k = *max_element(arr.begin(), arr.end());  // Find max element
    int removeCount = n / 20;  // 5% of the array
    double sum = 0;

    // Sort the array using countingSort
    countingSort(arr, k, n);

    // Remove the smallest and largest 5% elements
    for (int i = removeCount; i < n - removeCount; i++) {
        sum += arr[i];
    }

    return sum / (n - 2 * removeCount);  // Return the mean of the remaining elements
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double result = trimMean(arr);

    cout << "Mean after removing the smallest and largest 5%: " << result << endl;

    return 0;
}
