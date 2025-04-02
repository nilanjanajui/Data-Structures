#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string removeDuplicateLetters(string s)
{
    unordered_map<char, int> freq;
    unordered_set<char> inStack;
    stack<char> st;                

    for (char c : s)
    {
        freq[c]++;
    }

    for (char c : s)
    {
        freq[c]--; 

        if (inStack.count(c))
        {
            continue;
        }

        while (!st.empty() && c < st.top() && freq[st.top()] > 0)
        {
            inStack.erase(st.top());
            st.pop();
        }

        st.push(c);
        inStack.insert(c);
    }

    string result = "";
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main()
{
    string s;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Output: " << removeDuplicateLetters(s) << endl;

    return 0;
}

