// 8
// https://codeforces.com/contest/1380/problem/C

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Convert vector to array for selectionSort
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }

    // Sort the array using selectionSort
    selectionSort(arr, n);

    int team_count = 0;
    int team_size = 0;
    for (int i = n - 1; i >= 0; i--) {
        team_size++;
        if (team_size * arr[i] >= x) {
            team_count++;
            team_size = 0;
        }
    }

    cout << team_count << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
