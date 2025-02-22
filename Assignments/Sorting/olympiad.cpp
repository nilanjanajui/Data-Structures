// 17
// https://codeforces.com/problemset/problem/937/A

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    set<int> distinct_scores;
    for (int score : scores) {
        if (score > 0) {
            distinct_scores.insert(score);
        }
    }
    
    cout << distinct_scores.size() << endl;
    return 0;
}