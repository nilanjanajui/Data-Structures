// 38
/* https://onlinejudge.org/index.php?

option=com_onlinejudge&Itemid=8&category=32&page=show_problem&problem=982 */

#include <iostream>
#include <cmath>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // Assume the minimum is at index i

        // Find the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;  // Update the index of the minimum element
            }
        }

        // Swap A[i] with A[min] if needed
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int r;
        cin >> r;  // Number of relatives
        
        int streets[r];
        for (int i = 0; i < r; i++) {
            cin >> streets[i];
        }

        // Sort the streets array to find the median
        selectionSort(streets, r);

        // Find the median
        int median = streets[r / 2];
        
        // Calculate the minimal sum of distances to the median
        int sumOfDistances = 0;
        for (int i = 0; i < r; i++) {
            sumOfDistances += abs(streets[i] - median);
        }

        cout << sumOfDistances << endl;
    }

    return 0;
}
