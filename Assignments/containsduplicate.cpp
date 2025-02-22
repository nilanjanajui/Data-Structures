// 26
// https://leetcode.com/problems/contains-duplicate

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    string input;
    getline(cin, input);  // Read entire line

    vector<int> nums;
    stringstream ss(input);
    int num;

    while (ss >> num) {
        nums.push_back(num);
        if (ss.peek() == ',') ss.ignore(); // Ignore commas
    }

    if (containsDuplicate(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

