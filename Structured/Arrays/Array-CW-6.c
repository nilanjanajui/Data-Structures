#include<stdio.h>

int main()
{
    int data[5];
    int i, n, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements of the arrays\n", n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }
    max= data[0];
    min= data[0];

    for(i=1; i<n; i++)
    {
        if(data[i]>max)
        {
            max= data[i];
        }
        if(data[i]<min)
        {
            min= data[i];
        }
    }

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}