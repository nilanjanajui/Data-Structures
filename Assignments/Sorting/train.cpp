// 37
// https://onlinejudge.org/external/2/299.pdf

#include <iostream>
#include <vector>
using namespace std;

int countSwaps(vector<int>& arr, int L) {
    int swaps = 0;
    // Bubble sort technique to count adjacent swaps
    for (int i = 0; i < L - 1; i++) {
        for (int j = 0; j < L - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L;
        cin >> L;
        vector<int> arr(L);

        for (int i = 0; i < L; i++) {
            cin >> arr[i];
        }

        int result = countSwaps(arr, L);
        cout << "Optimal train swapping takes " << result << " swaps." << endl;
    }

    return 0;
}
