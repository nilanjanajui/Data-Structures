#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int> &heap, int index, int size)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
    {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        minHeapify(heap, smallest, size);
    }
}

void MaxToMin(vector<int> &heap)
{
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        minHeapify(heap, i, n);
    }
}


void printHeap(const vector<int> &heap)
{
    for (int val : heap)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    vector<int> heap;

    cout << "Number of nodes in Max Heap: ";
    cin >> n;

    cout << "Enter Max Heap: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        heap.push_back(x);
    }

    MaxToMin(heap);

    cout << "Min Heap: ";
    printHeap(heap);

    return 0;
}
