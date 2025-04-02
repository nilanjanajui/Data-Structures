#include <queue>
#include <iostream>
using namespace std;
int main()
{
    queue<int> qu1;
    queue<int> qu2;
    // pushing elements into first queue
    qu1.push(1);
    qu1.push(2);
    qu1.push(3);
    qu1.push(4);
    // pushing elements into 2nd queue
    qu2.push(3);
    qu2.push(5);
    qu2.push(7);
    qu2.push(9);
    // swap elements of queue
    qu1.swap(qu2);
    // printing the first queue
    cout << "Queue1 = ";
    while (!qu1.empty())
    {
        cout << qu1.front() << " ";
        qu1.pop();
    }
    // printing the second queue
    cout << endl << "Queue2 = ";
    while (!qu2.empty())
    {
        cout << qu2.front() << " ";
        qu2.pop();
    }
    return 0;
}