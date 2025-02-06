#include<stdio.h>

int main()
{
    int i, data[5];

    printf("Store values in an Array(5 integers): \n");
    
    for(i=0; i<5; i++) 
    {
        scanf("%d", &data[i]);
    }

    printf("Print Store Values: \n");

    for(i=0; i<5; i++)
    {
        printf("%d\n", data[i]);
    }

    return 0;
}