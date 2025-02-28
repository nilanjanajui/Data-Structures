#include<iostream>
#include<string>
using namespace std;

int MatchPattern (const string& T, const string& P) 
{
    int R = P.length();
    int S = T.length();

    int K = 1;
    int MAX = S - R + 1;

    while(K <= MAX) 
    {
        int L;

        for(L = 1; L <= R; L++) 
        {
            if(P[L] != T[K + L -1])
            {
                break;
            }
        }
        

        if (L == R) 
        {
            return K;
        }
        K = K + 1;
    }

    return 0;
}

int main()
{
    string T = "ababababab";
    string P = "abc";

    int index = MatchPattern(T, P);

    if (index != 0) 
    {
        cout << "Pattern found at position: " << index << endl;
    } 
    else 
    {
        cout << "Pattern not found." << endl;
    }

    return 0;
}
