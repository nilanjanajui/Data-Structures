// 3
// https://codeforces.com/contest/1430/problem/B

#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& A, int maxValue) {
    int n = A.size();
    vector<int> C(maxValue + 1, 0);
    vector<int> B(n); 

    // Step-2: Store the count of each element
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Step-3: Update C[i] to store the actual position of elements
    int index = 0;
    for (int i = 0; i <= maxValue; i++) {
        while (C[i]--) {
            B[index++] = i;
        }
    }

    // Step-4: Copy sorted elements back to A
    A = B;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);

    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        maxValue = max(maxValue, A[i]); // Track max value for counting sort
    }

    countingSort(A, maxValue); // Sort using Counting Sort

    int maxWater = A[n - 1]; // Start with the largest barrel
    for (int i = n - 2; i >= n - 1 - k && i >= 0; i--) {
        maxWater += A[i];
    }

    cout << maxWater << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
