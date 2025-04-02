#include <iostream>
#include <stack>
using namespace std;

string reverseStack(string S)
{
    stack<char> st;

    for (char c : S)
    {
        st.push(c);
    }

    string reversed = "";

    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main()
{
    string S;
    cout << "Enter a string: ";
    cin >> S;

    string result = reverseStack(S);
    cout << "Reversed string: " << result << endl;

    return 0;
}
