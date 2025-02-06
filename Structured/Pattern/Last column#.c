#include<stdio.h>

int main()
{
    int row, col, n;

    printf("How many rows of square?\n");
    scanf("%d", &n);

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n; col++)
        {
            if(col==n-row+1 || col==n)
            {
                printf("# ");
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