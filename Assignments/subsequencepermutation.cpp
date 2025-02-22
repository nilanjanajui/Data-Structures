// 20
// https://codeforces.com/problemset/problem/1552/A

#include <iostream>
#include <string>
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Convert the string to an integer array representing ASCII values
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = s[i];
        }

        // Sort the array using Insertion Sort
        insertionSort(a, n);

        // Convert the sorted array back to a string
        string sorted_s = s;
        for (int i = 0; i < n; i++) {
            sorted_s[i] = a[i];
        }

        // Count how many characters are already in the correct position
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == sorted_s[i]) {
                k++;
            }
        }

        // The minimum k is n - number of correct positions
        cout << n - k << endl;
    }
    return 0;
}
