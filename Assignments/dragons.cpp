// 10
// https://codeforces.com/problemset/problem/230/A

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<pair<int, int>>& dragons, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // assume the minimum is at index i

        // find the smallest element in the remaining array based on the first value of the pair (dragon's strength)
        for (int j = i + 1; j < n; j++) {
            if (dragons[j].first < dragons[min].first) {
                min = j;  // update the index of the minimum element
            }
        }

        // swap the dragons at index i and min
        if (min != i) {
            swap(dragons[i], dragons[min]);
        }
    }
}

void solve() {
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragons(n);
    
    for (int i = 0; i < n; i++) {
        cin >> dragons[i].first >> dragons[i].second;
    }

    // Sort dragons by strength (first value of pair) using selection sort
    selectionSort(dragons, n);

    // Try to defeat all dragons
    for (auto& dragon : dragons) {
        if (s > dragon.first) {  // Can defeat this dragon
            s += dragon.second;  // Gain the bonus
        } else {  // Can't defeat this dragon
            cout << "NO" << endl;
            return;
        }
    }

    // If we defeated all dragons
    cout << "YES" << endl;
}

int main() {
    solve();
    return 0;
}
