// 16
// https://codeforces.com/contest/1760/problem/A

#include <iostream>
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
    cin >> t;  // Number of test cases
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int arr[3] = {a, b, c};
        
        // Sort the array using Insertion Sort
        insertionSort(arr, 3);  

        // The second number is the median
        cout << arr[1] << endl;
    }
    return 0;
}
