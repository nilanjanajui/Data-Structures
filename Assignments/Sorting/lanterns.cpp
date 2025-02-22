// 25
// https://codeforces.com/problemset/problem/492/B

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int value = A[i];
        int j = i - 1;

        // Move elements that are greater than value one position ahead
        while (j >= 0 && A[j] > value) {  // Sorting in ascending order
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = value;
    }
}

int main() {
    int n, L;
    cin >> n >> L;  // Read number of lanterns and length of the street

    vector<int> lanterns(n);
    for (int i = 0; i < n; i++) {
        cin >> lanterns[i];  // Read lantern positions
    }

    // Convert vector to array for insertionSort
    int lanterns_arr[n];
    for (int i = 0; i < n; i++) {
        lanterns_arr[i] = lanterns[i];
    }

    // Sort the array using insertionSort
    insertionSort(lanterns_arr, n);

    // Calculate the maximum gap between consecutive lanterns
    double max_gap = 0;
    for (int i = 1; i < n; i++) {
        max_gap = max(max_gap, (double)(lanterns_arr[i] - lanterns_arr[i - 1]));
    }

    // Consider the edge cases: distance from 0 to the first lantern & last lantern to L
    double edge_gap = max(lanterns_arr[0], L - lanterns_arr[n - 1]);

    // The minimum required radius is the maximum of half the largest gap and edge gaps
    double result = max(max_gap / 2.0, edge_gap);

    cout << fixed << result << endl;  // Print the result with precision
    return 0;
}
