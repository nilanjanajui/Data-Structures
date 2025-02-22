// 24
// https://codeforces.com/problemset/problem/160/A

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int value = A[i];
        int j = i - 1;

        // Move elements that are greater than value one position ahead
        while (j >= 0 && A[j] < value) {  // Change the condition to sort in descending order
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = value;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        total_sum += coins[i];
    }

    // Convert vector to array for insertionSort
    int coins_arr[n];
    for (int i = 0; i < n; i++) {
        coins_arr[i] = coins[i];
    }

    // Sort the array in descending order using insertionSort
    insertionSort(coins_arr, n);

    int current_sum = 0;
    int coins_count = 0;
    for (int i = 0; i < n; i++) {
        current_sum += coins_arr[i];
        coins_count++;
        if (current_sum > (total_sum / 2)) {
            break;
        }
    }

    cout << coins_count << endl;
    return 0;
}
