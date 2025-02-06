#include<stdio.h>

int main()
{
    int n, row, col;
    
    printf("How many rows of squre?\n");
    scanf("%d", &n);

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n; col++)
        {
            if( col==row-n || col==n)
            {
                printf("$ ");
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}