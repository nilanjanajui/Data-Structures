// 30
// https://leetcode.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <vector>
#include <unordered_set>

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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Sort both arrays using selectionSort
    int n1 = nums1.size();
    int n2 = nums2.size();

    selectionSort(&nums1[0], n1);  // Sorting nums1
    selectionSort(&nums2[0], n2);  // Sorting nums2

    vector<int> result;
    int i = 0, j = 0;

    // Two-pointer approach to find common elements
    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    int n1, n2;
    cout << "Enter the size of nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "Enter the size of nums2: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    vector<int> res = intersection(nums1, nums2);
    cout << "Intersection: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
