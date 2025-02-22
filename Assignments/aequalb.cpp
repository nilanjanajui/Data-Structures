// 15
// https://vjudge.net/problem/CodeForces-1736A/origin

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    // Read array a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Read array b
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // Count flips needed
    int flip_0_to_1 = 0, flip_1_to_0 = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 1) {
            flip_0_to_1++;
        } else if (a[i] == 1 && b[i] == 0) {
            flip_1_to_0++;
        }
    }
    
    // The result is the maximum of these two counts
    cout << max(flip_0_to_1, flip_1_to_0) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
