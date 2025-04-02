#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    stack<char> s1_stack, s2_stack;

    for (char c : s1)
    {
        if (c == '#')
        {
            if (!s1_stack.empty())
                s1_stack.pop();
        }
        else
        {
            s1_stack.push(c);
        }
    }

    for (char c : s2)
    {
        if (c == '#')
        {
            if (!s2_stack.empty())
                s2_stack.pop();
        }
        else
        {
            s2_stack.push(c);
        }
    }

    bool equal = true;
    if (s1_stack.size() != s2_stack.size())
        equal = false;
    else
    {
        while (!s1_stack.empty())
        {
            if (s1_stack.top() != s2_stack.top())
            {
                equal = false;
                break;
            }
            s1_stack.pop();
            s2_stack.pop();
        }
    }

    if (equal)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}

