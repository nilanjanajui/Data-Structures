#include <iostream>
#include <vector>

using namespace std;

void heapifyUp(vector<int> &heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent])
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
    int n, value;

    vector<int> heap;

    cout << "Number of nodes in heap: ";
    cin >> n;

    cout << "Max Heap: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        insertNode(heap, x);
    }

    cout << "Enter value to insert: ";
    cin >> value;
    insertNode(heap, value);

    cout << "Heap after insertion: ";
    printHeap(heap);

    return 0;
}
