
// 2
// https://codeforces.com/problemset/problem/1760/B

#include <iostream>
#include <vector>
using namespace std;

void countingSort(string &s) {
    int count[26] = {0}; // Frequency array for 'a' to 'z'

    // Count occurrences of each character
    for (char c : s) {
        count[c - 'a']++;
    }

    // Reconstruct the sorted string
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i]--) {
            s[index++] = 'a' + i;
        }
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    countingSort(s); // Sort the string
    char maxchar = s.back(); // Last character in sorted order

    int result = maxchar - 'a' + 1;
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
