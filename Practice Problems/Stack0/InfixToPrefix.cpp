#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c)
{
    switch (c)
    {
        case '^': return 3;

        case '*': case '/': return 2;

        case '+': case '-': return 1;

        default: return -1;
    }
}

string reverseString(string str)
{
    int n = str.length();

    string reversed;

    for (int i = n - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    return reversed;
}

string InfixToPrefix(string infix)
{
    string reversedInfix = reverseString(infix);

    for (size_t i = 0; i < reversedInfix.length(); i++)
    {
        if (reversedInfix[i] == '(')
        {
            reversedInfix[i] = ')';
        }
        else if (reversedInfix[i] == ')')
        {
            reversedInfix[i] = '(';
        }
    }

    stack<char> s;
    string prefix;

    for (size_t i = 0; i < reversedInfix.length(); i++)
    {
        char ch = reversedInfix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            prefix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop(); // Pop '('
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && precedence(ch) < precedence(s.top()))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    return reverseString(prefix);
}

int main()
{
    string infix_exp, prefix_exp;

    cout << "Enter an Infix Expression: ";
    cin >> infix_exp;

    prefix_exp = InfixToPrefix(infix_exp);

    if (prefix_exp != "Invalid Expression")
    {
        cout << "PREFIX EXPRESSION: " << prefix_exp << endl;
    }
    else
    {
        cout << prefix_exp << endl;
    }

    return 0;
}
