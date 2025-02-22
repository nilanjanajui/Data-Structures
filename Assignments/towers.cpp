// 21
// https://vjudge.net/problem/CodeForces-37A

#include <iostream>
using namespace std;

// Insertion Sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Read input values
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sort the array using Insertion Sort
    insertionSort(arr, n);
    
    int max_height = 1, unique_count = 1, current_height = 1;
    
    // Count the max tower height and number of unique towers
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_height++;
            max_height = max(max_height, current_height);
        } else {
            unique_count++;
            current_height = 1;
        }
    }
    
    // Output the results
    cout << max_height << " " << unique_count << endl;
    return 0;
}
