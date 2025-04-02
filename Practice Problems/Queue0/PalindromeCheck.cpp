#include <iostream>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

int main()
{
    stack<char> s;
    queue<char> q;
    char ch;
    int mismatches = 0;

    cout << "Enter string: " << endl;
    while (cin.get(ch) && ch != '\n')
    { 
        if (isalpha(ch))
        {
            char upperCh = toupper(ch);
            s.push(upperCh);
            q.push(upperCh);
        }
    }

    while (!s.empty() && !q.empty())
    {
        if (s.top() != q.front())
        {
            ++mismatches;
        }
        s.pop();
        q.pop();
    }

    if (mismatches == 0)
        cout << "That is a palindrome" << endl;
    else
        cout << "That is not a palindrome" << endl;

    return 0;
}
