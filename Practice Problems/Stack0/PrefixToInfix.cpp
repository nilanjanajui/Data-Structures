#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string PrefixToInfix(string prefix)
{
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string op(1, prefix[i]);
            // string op = prefix[i];
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}

int main()
{
    string infix, prefix;
    cout << "Enter a PREFIX Expression : ";
    cin >> prefix;

    infix = PrefixToInfix(prefix);

    cout << "INFIX EXPRESSION: " << infix;

    return 0;
}