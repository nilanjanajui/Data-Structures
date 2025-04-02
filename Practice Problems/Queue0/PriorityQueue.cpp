#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Top element: " << pq.top() << endl;

    cout << "Elements in priority order: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

