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

    // Process s1
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

    // Process s2
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

    // Compare the resulting strings
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

    // Output result
    if (equal)
        cout << true << endl;
    else
        cout << false << endl;

    return 0;
}
