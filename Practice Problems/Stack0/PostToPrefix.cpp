#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string PostfixToPrefix(string postfix)
{
    stack<string> s;
    for (size_t i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(postfix[i] + op2 + op1);
        }
    }
    return s.top();
}

int main()
{

    string prefix, postfix;
    cout << "Enter a POSTFIX Expression : ";
    cin >> postfix;

    prefix = PostfixToPrefix(postfix);

    cout << "PREFIX EXPRESSION: " << prefix;

    return 0;
}

