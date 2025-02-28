#include <iostream>

using namespace std;

int palindrome(int A[], int begin, int end)
{
    if (begin >= end)
    {
        return 1;
    }
    if (A[begin] == A[end])
    {
        return palindrome(A, begin + 1, end - 1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int N;

    cout << "Number of elements: ";
    cin >> N;

    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    if (palindrome(A, 0, N - 1) == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
