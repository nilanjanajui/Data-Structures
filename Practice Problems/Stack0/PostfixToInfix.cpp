#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string PostfixToInfix(string postfix)
{
    stack<string> s;

    for (size_t i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (isOperand(ch))
        {
            string operand(1, ch);
            s.push(operand);
        }
        else if (isOperator(ch))
        {
            if (s.size() < 2)
            {
                return "Invalid Expression";
            }

            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            string expression = "(" + op1 + " " + ch + " " + op2 + ")";
            s.push(expression);
        }
        else
        {
            return "Invalid Expression";
        }
    }

    if (s.size() != 1)
    {
        return "Invalid Expression";
    }

    return s.top();
}

int main()
{
    string postfix_exp, infix_exp;
    cout << "Enter a Postfix Expression: ";
    cin >> postfix_exp;

    infix_exp = PostfixToInfix(postfix_exp);

    if (infix_exp != "Invalid Expression")
    {
        cout << "INFIX EXPRESSION: " << infix_exp << endl;
    }
    else
    {
        cout << infix_exp << endl;
    }

    return 0;
}
