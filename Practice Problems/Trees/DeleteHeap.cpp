#include <iostream>
#include <vector>

using namespace std;


void heapifyDown(vector<int> &heap, int index)
{
    int size = heap.size();
    while (index < size)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

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
            index = largest;
        }
        else
        {
            break;
        }
    }
}

void deleteMax(vector<int> &heap)
{
    if (heap.empty())
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    cout << "Deleted max value: " << heap[0] << endl;

    heap[0] = heap.back(); 
    heap.pop_back();      

    heapifyDown(heap, 0);
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

    cout << "Number of nodes in heap: ";
    cin >> n;

    cout << "Max Heap: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        heap.push_back(x);
    }

    deleteMax(heap);

    cout << "Heap after deletion: ";
    printHeap(heap);

    return 0;
}
