// 34
// https://leetcode.com/problems/minimum-absolute-difference/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& A, int k, int n) {
    vector<int> C(k + 1, 0);
    vector<int> B(n);  // Output array

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    A = B;  // Copy the sorted array back to A
}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int n = arr.size();  // Get the size of the input array
    int k = *max_element(arr.begin(), arr.end());  // Find the maximum element in the array
    int minDiff = INT_MAX;  // Initialize the minimum difference to the largest possible value
    vector<vector<int>> result;  // Create a 2D vector to store the result

    countingSort(arr, k, n);  // Sort the array using countingSort

    for (int i = 1; i < n; i++) {  // Iterate through the sorted array
        int diff = arr[i] - arr[i - 1];  // Calculate the absolute difference between adjacent elements
        if (diff < minDiff) {  // If we find a smaller difference
            minDiff = diff;  // Update the minimum difference
            result.clear();  // Clear the previous pairs (if any)
            result.push_back({arr[i - 1], arr[i]});  // Add the new pair to the result
        } else if (diff == minDiff) {  // If the difference equals the current minimum difference
            result.push_back({arr[i - 1], arr[i]});  // Add the pair to the result
        }
    }

    return result;  // Return the result containing pairs with the minimum absolute difference
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);  // Create a vector of size n to store the input elements
    cout << "Enter the elements: "; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    }

    vector<vector<int>> result = minimumAbsDifference(arr);  

    cout << "Pairs with minimum absolute difference: "; 
    for (auto& pair : result) {  // Iterate over the result
        cout << "[" << pair[0] << "," << pair[1] << "] ";  // Print each pair
    }
    cout << endl;

    return 0;
}
