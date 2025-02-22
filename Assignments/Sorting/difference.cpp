// 27
// https://leetcode.com/problems/find-the-difference/

#include <iostream>
using namespace std;

void insertionSort(char A[], int n) {
    for (int i = 1; i < n; i++) {
        char value = A[i];
        int j = i - 1;

        // Move elements that are greater than value one position ahead
        while (j >= 0 && A[j] > value) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = value;
    }
}

char findTheDifference(string s, string t) {
    // Convert strings to arrays of characters
    int n = s.size();
    int m = t.size();

    char s_array[n];
    char t_array[m];

    for (int i = 0; i < n; i++) {
        s_array[i] = s[i];
    }

    for (int i = 0; i < m; i++) {
        t_array[i] = t[i];
    }

    // Sort both arrays using insertionSort
    insertionSort(s_array, n);
    insertionSort(t_array, m);

    // Compare the two sorted arrays character by character
    for (int i = 0; i < n; i++) {
        if (s_array[i] != t_array[i]) {
            return t_array[i];  // The character in t that is not in s
        }
    }

    // If no differences are found in the common length, the extra character is the last one in t
    return t_array[m - 1];
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << findTheDifference(s, t) << endl;
    return 0;
}
