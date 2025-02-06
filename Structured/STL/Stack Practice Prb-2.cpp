//Given a string, str, the task is to remove all the duplicate adjacent characters from the given string.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    
    stack<char> stk;
    string str;
    string s2;
    cout << "Enter a string: ";
    cin >> str;
    
    for (char ch : str) 
    {
        if (stk.empty() || ch != stk.top()) 
        {
            stk.push(ch);
            
        } 
        else 
        {
            stk.pop();
        }
    }

    if(stk.empty())
    {
        cout<< "Empty String" << endl;
    }

    while (!stk.empty()) 
    {
        s2 = stk.top() + s2;
        stk.pop();
    }

    cout << s2 << endl;
    
    return 0;
}