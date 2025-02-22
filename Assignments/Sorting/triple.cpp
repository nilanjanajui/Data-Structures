// 23
// https://codeforces.com/problemset/problem/1669/B

#include <iostream>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> freq;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;

        if (freq[x] == 3 && ans == -1) {
            ans = x;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

