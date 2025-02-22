// 35
// https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& A, int k, int n) {
    // Step 1: Initialize the count array
    vector<int> C(k + 1, 0);
    vector<int> B(n);  // Output array

    // Step 2: Count the occurrences of each element in A
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Step 3: Update C[i] to store the actual position of elements
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // Step 4: Build the output array
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    // Step 5: Copy sorted elements back to A
    A = B;
}

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int k = 2;  // Maximum value in nums (0, 1, or 2)
    
    // Apply counting sort
    countingSort(nums, k, n);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sortColors(nums);

    // Output sorted array
    cout << "Sorted Colors: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
