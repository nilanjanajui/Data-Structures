// 39
// https://vjudge.net/problem/UVA-10107

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> numbers;
    int num;
    
    while (cin >> num) {
        numbers.push_back(num);
        selectionSort(numbers);  // Sort the array up to the current point
        
        int n = numbers.size();
        if (n % 2 == 1) {
            // Odd size, take the middle element
            cout << numbers[n / 2] << endl;
        } else {
            // Even size, take the average of the two middle elements
            int median = (numbers[n / 2 - 1] + numbers[n / 2]) / 2;
            cout << median << endl;
        }
    }

    return 0;
}
