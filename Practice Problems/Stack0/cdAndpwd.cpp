// https://codeforces.com/contest/158/problem/C

#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

stack<string> processPath(const string &path, stack<string> &dirStack)
{
    if (path[0] == '/')
    {
        while (!dirStack.empty())
            dirStack.pop();
    }

    stringstream ss(path);
    string dir;
    while (getline(ss, dir, '/'))
    {
        if (dir == ".." && !dirStack.empty())
        {
            dirStack.pop();
        }
        else if (!dir.empty() && dir != "..")
        {
            dirStack.push(dir); 
        }
    }
    return dirStack;
}

void printPwd(stack<string> dirStack)
{
    if (dirStack.empty())
    {
        cout << "/" << endl;
        return;
    }

    string path = "";
    stack<string> temp;
    while (!dirStack.empty())
    {
        temp.push(dirStack.top());
        dirStack.pop();
    }

    while (!temp.empty())
    {
        path += "/" + temp.top();
        temp.pop();
    }
    cout << path << "/" << endl;
}

int main()
{
    int n;
    cin >> n;
    string command, path;
    stack<string> dirStack;

    while (n--)
    {
        cin >> command;
        if (command == "pwd")
        {
            printPwd(dirStack);
        }
        else if (command == "cd")
        {
            cin >> path;
            dirStack = processPath(path, dirStack);
        }
    }
    return 0;
}

