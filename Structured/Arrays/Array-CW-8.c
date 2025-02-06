#include<stdio.h>

int main()
{
    int ar[10];
    int i, n;
    int sum=0;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for(i=0; i<n; i++)
    {
        sum+=ar[i];
    }
    float mean = (float)sum/n;
    float diffArray[n];

    for(i=0; i<n; i++)
    {
        diffArray[i]=ar[i]-mean;
    }
    printf("Mean: %.2f\n", mean);

    printf("Differances:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%.2f\n", diffArray[i]);
    }

    return 0;

}