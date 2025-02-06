//Write a program to calculate the frequency of each word in the given string.

#include<iostream>
#include<map>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s="learning to code is learning to create and innovate";

    map<string, int>m;
    stringstream ss(s);
    string eachword;

    while(ss>>eachword)
    {
        if(m.find(eachword)==m.end())
        {
            m.insert(make_pair(eachword, 1));
        }
        else
        {
            m[eachword]++;
        }
    }
    
    map<string, int>::iterator itr;
    for(itr=m.begin();itr!=m.end();++itr)
    {
        cout<<'\t' << (*itr).first << '\t' << (*itr).second <<'\n';
    }
    return 0;
}