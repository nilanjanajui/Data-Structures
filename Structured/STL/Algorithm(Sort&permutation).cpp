/*• sort
– Reorders a given range.
– Can also plug in a functor to change the ordering function
• next_permutation 
– Generates a specific kind of reordering, called a “permutation”.
– Can use to generate all possible orders of a given sequence. */

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s="asdf";
    cout<<" original: "<< s<< endl;

    sort(s.begin(), s.end());
    cout<< " sorted: "<< s << endl;

    string t(s);
    cout<<" permutation: "<< endl;

    do {
        next_permutation (s.begin(), s.end());
        cout<< s << " ";
    } while(s!=t);

    return 0;
}

