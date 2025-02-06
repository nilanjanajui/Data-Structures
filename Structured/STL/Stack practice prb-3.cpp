
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    stack<char> stack1, stack2;

    for (char c : s1)
    {
        if (c == '#')
        {
            if (!stack1.empty())
            {
                stack1.pop();
            }
        }
        else
        {
            stack1.push(c);
        }
    }

    for (char c : s2)
    {
        if (c == '#')
        {
            if (!stack2.empty())
            {
                stack2.pop();
            }
        }
        else
        {
            stack2.push(c);
        }
    }

    while (!stack1.empty() && !stack2.empty())
    {
        if (stack1.top() != stack2.top())
        {
            cout << "false" << endl;
            return 0;
        }

        stack1.pop();
        stack2.pop();
    }

    if (stack1.empty() && stack2.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
