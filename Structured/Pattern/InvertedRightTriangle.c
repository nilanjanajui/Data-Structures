#include<stdio.h>

int main()
{
    int n, row, col, space;
    
    printf("How many rows of inverted right triangle?\n");
    scanf("%d", &n);

    for(row=n; row>=1; row--)
    {
        for(space=1; space<=n-row; space++)
        {
            printf("  ");
        }
        for(col=1; col<=row; col++)
        {
            printf("* ");
        }
            
        printf("\n");
    }

    return 0;
}