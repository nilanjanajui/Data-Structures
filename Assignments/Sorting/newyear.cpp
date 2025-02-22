// 21
// https://codeforces.com/problemset/problem/723/A

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
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    // Store the positions in an array
    int positions[] = {x1, x2, x3};

    // Sort the array using Insertion Sort
    insertionSort(positions, 3);

    // Minimum total distance to bring all to middle point
    int min_distance = (positions[2] - positions[1]) + (positions[1] - positions[0]);

    cout << min_distance << endl;
    return 0;
}
