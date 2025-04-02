//Given a string, str, the task is to remove all the duplicate adjacent characters from the given string.

#include<iostream>
#include<queue>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1;

    cin >> s1;

    stack<char> stk;
    stack<char> cpy;
    queue<char> qu;

    for (char &C : s1)
    {
        if (stk.empty() || C != stk.top())
        {
            stk.push(C);
        }
        else
        {
            stk.pop();
        }
    }
    while (!stk.empty())
    {
        cpy.push(stk.top());
        stk.pop();
    }
    while (!cpy.empty())
    {
        qu.push(cpy.top());
        cpy.pop();
    }

    if(qu.empty())
    {
        cout<< "Empty String" << endl;
    }

    while (!qu.empty())
    {
        cout << qu.front();
        qu.pop();
    }

    return 0;
}

