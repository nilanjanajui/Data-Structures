// 18
// https://vjudge.net/problem/CodeForces-1399A/origin

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

void solve() {
    int n;
    cin >> n;
    int a[n];  // Declare an array of size n

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the array using Insertion Sort
    insertionSort(a, n);  

    // Check if any two consecutive elements have a difference greater than 1
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
