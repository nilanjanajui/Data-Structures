#include <iostream>
#include <queue>

using namespace std;

void push(queue<int> &queue1, int x)
{
    queue1.push(x);
}

int pop(queue<int> &queue1, queue<int> &queue2)
{
    while (queue1.size() > 1)
    {
        queue2.push(queue1.front());
        queue1.pop();
    }

    int topElement = queue1.front();
    queue1.pop();

    swap(queue1, queue2);

    return topElement;
}

int top(queue<int> &queue1, queue<int> &queue2)
{
    while (queue1.size() > 1)
    {
        queue2.push(queue1.front());
        queue1.pop();
    }

    int topElement = queue1.front();

    queue2.push(queue1.front());
    queue1.pop();

    swap(queue1, queue2);

    return topElement;
}

bool empty(queue<int> &queue1)
{
    return queue1.empty();
}

int main()
{
    queue<int> queue1, queue2;

    push(queue1, 1);
    push(queue1, 2);

    cout << "Top: " << top(queue1, queue2) << endl;                 
    cout << "Pop: " << pop(queue1, queue2) << endl;                 
    cout << "Top: " << top(queue1, queue2) << endl;  
    cout << "Is Empty? " << (empty(queue1) ? "Yes" : "No") << endl; 

    return 0;
}
