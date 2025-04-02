#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findNextHigherPeaks(vector<int> &heights)
{
    int n = heights.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; ++i)
    {
        queue<int> q;

        for(int j = i + 1; j < n; ++j)
        {
            if(heights[j] > heights[i])
            {
                result[i] = heights[j];
                break;
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n; 

    vector<int> heights(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> heights[i]; 
    }

    findNextHigherPeaks(heights); 

    return 0;
}
