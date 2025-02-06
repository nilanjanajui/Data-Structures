#include<iostream>
#include<set>

using namespace std;
int main()
{
    set<char> a; //for ascending order
    // set<char,greater<char>>a; for descending order
    a.insert('G');
    a.insert('F');
    a.insert('G');

    for(char st: a)
    {
        cout<<st<<" ";
    }
    cout<<"\n";
    return 0;
}