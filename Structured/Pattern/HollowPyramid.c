#include <stdio.h>

int main() 
{
    int n, row, col;

    printf("How many rows for hollow full pattern pyramid?\n");
    scanf("%d", &n);

    for (row=1; row<=n; row++) 
    {
        for (col=1; col<=2*n-1; col++) 
        {
            if (row==n || row+col==n+1 || col-row==n-1) 
            {
                printf("* ");
            } 
            else 
            {
                printf("  ");
            }
        }

        printf("\n");
    }

    return 0;
}