#include <iostream>
using namespace std;

int binarySearch(int data[], int lb, int ub, int item)
{
    int beg = lb, end = ub, mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (data[mid] == item)
        {
            return mid;
        }
        else if (item < data[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int data[] = {6, 13, 14, 25, 33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97};
    int size = sizeof(data) / sizeof(data[0]);
    int item = 33;

    int result = binarySearch(data, 0, size - 1, item);

    if (result != -1)
        cout << "Item found at index: " << result << endl;
    else
        cout << "Item not found." << endl;

    return 0;
}
