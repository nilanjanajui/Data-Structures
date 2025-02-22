// 11
// https://codeforces.com/problemset/problem/1676/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& A, int k, int n) {
    vector<int> C(k + 1, 0);
    vector<int> B(n);

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    A = B;
}

void solve() {
    int n;
    cin >> n;
    vector<int> candies(n);

    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    int max_candy = *max_element(candies.begin(), candies.end());
    int min_candy = *min_element(candies.begin(), candies.end());

    // We need to perform counting sort between the minimum and maximum candy values.
    countingSort(candies, max_candy, n);

    int total_moves = 0;
    for (int i = 0; i < n; i++) {
        total_moves += (candies[i] - min_candy);
    }

    cout << total_moves << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
