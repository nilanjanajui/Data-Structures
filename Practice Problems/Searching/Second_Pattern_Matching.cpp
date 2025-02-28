#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to create the pattern matching table (transition function)
vector<vector<int>> computeTransitionFunction(const string &P, int alphabetSize)
{
    int R = P.length();
    vector<vector<int>> F(R + 1, vector<int>(alphabetSize, 0));

    for (int state = 0; state <= R; state++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            string prefix = P.substr(0, state) + c;
            int nextState = 0;

            for (int i = 1; i <= state + 1; i++)
            {
                if (prefix.substr(prefix.length() - i) == P.substr(0, i))
                {
                    nextState = i;
                }
            }

            F[state][c - 'a'] = nextState;
        }
    }
    return F;
}

// Function to implement the pattern matching algorithm
int matchPattern(const string &T, const string &P)
{
    int N = T.length();
    int R = P.length();
    vector<vector<int>> F = computeTransitionFunction(P, 26);

    int SK = 0;
    int K = 0;

    while (K < N)
    {
        SK = F[SK][T[K] - 'a'];
        K++;

        if (SK == R)
        { // Match found
            return K - R;
        }
    }

    return 0; // Pattern not found
}

// Main function
int main()
{
    string T = "ababababc";
    string P = "abc";

    int index = matchPattern(T, P);

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
