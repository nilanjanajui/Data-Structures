// 1
// https://codeforces.com/problemset/problem/141/A

#include <iostream>
using namespace std;

// Selection Sort function
void selectionSort(string &s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(s[i], s[minIndex]);
        }
    }
}

int main() {
    string guest, host, pile;
    cin >> guest >> host >> pile;

    string combined = guest + host;

    selectionSort(combined);
    selectionSort(pile);

    if (combined == pile) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
