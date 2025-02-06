#include<stdio.h>

int main()
{
    int n, i;
    int ar[10];
    float sum=0, mean;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
        sum+= ar[i];
    }

    mean= sum/n;

    printf("Mean = %.2f\n", mean);

    return 0;
}