// 4
// https://codeforces.com/contest/1334/problem/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function for counting sort used in radix sort
void countingSort(vector<int>& a, int n, int exp) {
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences
    for (int i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    // Update count[i] to hold the actual position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array in descending order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

// Function for radix sort
void radixSort(vector<int>& a, int n) {
    int maxVal = *max_element(a.begin(), a.end());
    
    // Perform counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(a, n, exp);
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    radixSort(a, n); // Sort in descending order using radix sort

    long long total_savings = 0;
    for (int i = 0; i < n; i++) {
        total_savings += a[i];
    }

    int wealthy_count = 0;
    int current_sum = 0;

    for(int i = 0; i < n; i++) {
        current_sum += a[i];
        if ((current_sum / (i + 1)) >= x) {
            wealthy_count = i + 1;
        }
        else {
            break;
        }
    }
    cout << wealthy_count << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
