#include<iostream>
#include<string>
using namespace std;

void LCS(string X, string Y)
{
    int n = X.size(), m = Y.size();
    int L[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if(X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }


    int i = n, j = m;
    string lcs_str;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs_str = X[i - 1] + lcs_str;
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "LCS Length: " << L[n][m] << endl;
    cout << "LCS String: " << lcs_str << endl;
}

int main()
{
    string X = "PRESIDENT", Y = "PROVIDENCE";
    LCS(X, Y);

    return 0;
}


