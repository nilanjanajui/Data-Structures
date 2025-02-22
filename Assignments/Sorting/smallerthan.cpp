// 29
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // Assume the minimum is at index i

        // Find the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;  // Update the index of the minimum element
            }
        }

        // Swap A[i] with A[min] if needed
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> sortedNums = nums;  // Copy original array
    int n = sortedNums.size();

    // Convert vector to array for selectionSort
    int sortedArray[n];
    for (int i = 0; i < n; i++) {
        sortedArray[i] = sortedNums[i];
    }

    // Sort using selectionSort
    selectionSort(sortedArray, n);

    unordered_map<int, int> numCount;
    for (int i = 0; i < n; i++) {
        if (numCount.find(sortedArray[i]) == numCount.end()) {
            numCount[sortedArray[i]] = i;
        }
    }

    vector<int> result;
    for (int num : nums) {
        result.push_back(numCount[num]);  // Add the number of elements smaller than current
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = smallerNumbersThanCurrent(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
