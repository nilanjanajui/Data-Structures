#include <iostream>
#include <vector>
using namespace std;

int findStartingPump(int n, vector<pair<int, int>> &pumps)
{
    int total_petrol = 0, total_distance = 0, balance = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        total_petrol += pumps[i].first;
        total_distance += pumps[i].second;
        balance += pumps[i].first - pumps[i].second;

        if (balance < 0)
        {
            start = i + 1;
            balance = 0;   
        }
    }

    return (total_petrol >= total_distance) ? start : -1;
}

int main()
{
    int n;

    cout << "Number of petrol pump: ";
    cin >> n;

    vector<pair<int, int>> pumps(n);

    cout << "Amount of petrol(L) & Distance(km) between each pumps: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pumps[i].first >> pumps[i].second;
    }

    cout << "Found staring pump at: " << findStartingPump(n, pumps) << endl;

    return 0;
}
