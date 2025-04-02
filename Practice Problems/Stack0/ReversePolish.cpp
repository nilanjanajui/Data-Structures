#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for(string token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();

            char op = token[0];
            switch (op) 
            {
                case '+': st.push(num1 + num2); 
                    break;
                case '-': st.push(num1 - num2); 
                    break;
                case '*': st.push(num1 * num2); 
                    break;
                case '/': st.push(num1 / num2); 
                    break;
                default: break;
            }
        }
        else
        {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main()
{
    vector<string> tokens;
    string token;
    int n;

    cout << "Enter the number of tokens: ";
    cin >> n;
    cout << "Enter the tokens (operands and operators in RPN order):\n";

    for (int i = 0; i < n; i++)
    {
        cin >> token;
        tokens.push_back(token);
    }

    cout << "Output: " << evalRPN(tokens) << endl;

    return 0;
}

