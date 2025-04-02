// Given two strings s1 and s2, let us assume that while typing the strings there were some backspaces
// encountered which are represented by #. 
// The task is to determine whether the resultant strings after processing the
// backspace character would be equal or not.

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    queue<char> q1, q2;

    for (char c : s1)
    {
        if (c == '#')
        {
            if (!q1.empty())
                q1.pop();
        }
        else
        {
            q1.push(c);
        }
    }

    for (char c : s2)
    {
        if (c == '#')
        {
            if (!q2.empty())
                q2.pop();
        }
        else
        {
            q2.push(c);
        }
    }

    bool equal = true;
    if (q1.size() != q2.size())
        equal = false;
    else
    {
        while (!q1.empty())
        {
            if (q1.front() != q2.front())
            {
                equal = false;
                break;
            }
            q1.pop();
            q2.pop();
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


