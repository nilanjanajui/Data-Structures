//multiplication
#include<stdio.h>

int main()
{
    int A[2][2], B[2][2], i, j, k, sum[2][2], M[2][2];

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
            M[i][j]=0;
            
            for(k=0; k<2; k++)
            {
                M[i][j]=M[i][j]+(A[i][k]*B[k][j]);
            }
        }
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}