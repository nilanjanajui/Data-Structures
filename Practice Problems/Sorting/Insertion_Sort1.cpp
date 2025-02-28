#include<iostream>
using namespace std;

void InsertionSort(int Arr[], int n) 
{
    for(int i = 1; i<n; i++) 
    {
        int CurrentValue = Arr[i];
        int j = i-1;

        while(j >= 0 && CurrentValue < Arr[j])
        {
            Arr[j+1] = Arr[j];
            j--;
        }

        Arr[j+1] = CurrentValue;
    }
}

int main() 
{
    int Arr[] = {77, 42, 35, 12, 101, 5};
    int n = 6;

    InsertionSort(Arr, n);

    cout << "Sorted array: " << endl;

    for(int i = 0; i < n; i++)
    {
        cout << Arr[i] << " " ;
    }

    return 0;

}

