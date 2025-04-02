#include <iostream>
#include <stack>

using namespace std;

stack<int> stack1, stack2;

void push(int x)
{
    stack1.push(x);
}

int pop()
{
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    if (stack2.empty())
    {
        cout << "Queue is empty!" << endl;
        return -1; 
    }

    int front = stack2.top();
    stack2.pop();
    return front;
}

int peek()
{
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    if (stack2.empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    return stack2.top();
}

bool empty()
{
    return stack1.empty() && stack2.empty();
}

int main()
{
    push(1);
    push(2);
    cout << "Peek: " << peek() << endl;   
    cout << "Pop: " << pop() << endl;    
    cout << "Empty: " << empty() << endl; 
    cout << "Pop: " << pop() << endl;    
    cout << "Empty: " << empty() << endl;

    return 0;
}
