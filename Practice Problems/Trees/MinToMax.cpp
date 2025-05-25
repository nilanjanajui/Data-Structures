#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> &heap, int index, int size)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        maxHeapify(heap, largest, size);
    }
}

void MinToMax(vector<int> &heap)
{
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        maxHeapify(heap, i, n);
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

    cout << "Number of nodes Min Heap: ";
    cin >> n;

    cout << "Min Heap: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        heap.push_back(x);
    }

    MinToMax(heap);

    cout << "Max Heap: ";
    printHeap(heap);

    return 0;
}
