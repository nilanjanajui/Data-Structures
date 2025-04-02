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

        case '*':
        case '/': return 2;

        case '+':
        case '-': return 1;

        default: return -1;
    }
}

string InfixToPostfix(string infix)
{

    stack<char> s;

    string postfix;

    for (size_t i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {

            s.push(ch);
        }

        else if (ch == ')')
        {

            while (!s.empty() && s.top() != '(')
            {
                char temp = s.top();

                postfix += temp;

                s.pop();
            }

            if (!s.empty())
            {
                s.pop();
            }
            else
            {
                return "Invalid Expression";
            }
        }

        else if (isOperator(ch))
        {
            if (s.empty())
            {
                s.push(ch);
            }
            else
            {
                while (!s.empty() && precedence(ch) <= precedence(s.top()))
                {
                    char temp = s.top();

                    postfix += temp;

                    s.pop();
                }

                s.push(ch);
            }
        }
    }

    while (!s.empty())
    {

        char temp = s.top();

        postfix += temp;

        s.pop();
    }

    return postfix;
}

int main()
{
    string infix_exp, postfix_exp;

    cout << "Enter a Infix Expression: ";

    cin >> infix_exp;

    postfix_exp = InfixToPostfix(infix_exp);

    if (postfix_exp != "Invalid Expression")
    {
        cout << "POSTFIX EXPRESSION: " << postfix_exp << endl;
    }
    else
    {
        cout << postfix_exp << endl;
    }

    return 0;
}

