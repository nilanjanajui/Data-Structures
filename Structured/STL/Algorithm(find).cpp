//• find – Find an element in a vector

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<string> v;
    v.push_back("abc");
    v.push_back("xyz");

    if(std::find(v.begin(), v.end(), "abc") != v.end())
    {
        cout<<"Word not found"<< endl;
    }
    else
    {
        cout<<"Word found"<< endl;
    }

    return 0;
}