#include <iostream>
#include <vector>

using namespace std;

void heapifyUp(vector<int> &heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent])
        {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void insertNode(vector<int> &heap, int value)
{
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
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
    int n, val;
    vector<int> minHeap;

    cout << "Number of nodes: ";
    cin >> n;

    cout << "nodes: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertNode(minHeap, val);
    }

    cout << "Min Heap: ";
    printHeap(minHeap);

    return 0;
}
