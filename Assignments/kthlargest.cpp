// 31
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Add elements to the min-heap
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove the smallest element
        }
    }

    return minHeap.top();  // The root of the heap is the kth largest element
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
