// 13
// https://codeforces.com/problemset/problem/339/A

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;       // assume the minimum is at index i

        // find the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;        // update the index of the minimum element
            }
        }

        // swap A[i] with A[min] if needed
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

int main() {
    string s;
    cin >> s;

    // Convert string digits to integer array
    vector<int> numbers;
    for (char c : s) {
        if (c != '+') {
            numbers.push_back(c - '0');  // convert char to int
        }
    }

    // Apply Selection Sort
    selectionSort(&numbers[0], numbers.size());

    // Print the sorted numbers with '+' in between
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) cout << "+";
        cout << numbers[i];
    }
    cout << endl;

    return 0;
}
