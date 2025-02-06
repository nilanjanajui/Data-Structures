//Summation
#include<stdio.h>

int main()
{
    int A[2][2], B[2][2], i, j, sum[2][2];

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            scanf("%d", &A[i][j]);    
        }
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
           scanf("%d", &B[i][j]);  
        }
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            sum[i][j]=A[i][j]+B[i][j];
        }
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}