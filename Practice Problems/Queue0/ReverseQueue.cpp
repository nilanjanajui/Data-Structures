#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int> &q)
{

    if (q.empty())
    {
        return;
    }

    int frontElement = q.front();
    q.pop();

    reverseQueue(q);

    q.push(frontElement);
}

int main()
{
    int T;

    cout << "Number of test cases: ";
    cin >> T;

    
    while (T--)
    {
        int N;

        cout << "number of elements: ";
        cin >> N;

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        reverseQueue(q);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    return 0;
}
