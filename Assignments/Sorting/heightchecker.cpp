// 28
// https://leetcode.com/problems/height-checker/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int value = A[i];
        int j = i - 1;

        // Move elements that are greater than value one position ahead
        while (j >= 0 && A[j] > value) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = value;
    }
}

int heightChecker(vector<int>& heights) {
    vector<int> expected = heights;  // Copy original array
    int n = heights.size();

    // Convert vector to array for insertionSort
    int expectedArray[n];
    for (int i = 0; i < n; i++) {
        expectedArray[i] = expected[i];
    }

    // Sort using insertionSort
    insertionSort(expectedArray, n);

    // Compare the heights with the expected sorted heights
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (heights[i] != expectedArray[i]) {
            count++;  // Count mismatches
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << heightChecker(heights) << endl;
    return 0;
}
