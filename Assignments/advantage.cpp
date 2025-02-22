// 7
// https://codeforces.com/contest/1760/problem/C

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if(A[j] < A[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Apply Selection Sort
    selectionSort(s.data(), n);

    int max1 = s[n - 1];
    int max2 = s[n - 2];

    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            cout << s[i] - max2 << " ";
        } else {
            cout << s[i] - max1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
