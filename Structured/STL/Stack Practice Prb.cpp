//Given a line of text, reverse the text without reversing the individual words

#include<iostream>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1="Technical Interview Preperation";
    stack<string> s2;

    stringstream ss(s1);
    string eachword;

    while(ss>>eachword)
    {
        s2.push(eachword);
    }
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    return 0;
}