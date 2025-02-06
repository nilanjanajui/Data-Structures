#include<stdio.h>

int main()
{
    int n, row, col, space;

    printf("How many rows of inverted full pyramid?\n");
    scanf("%d", &n);

    for(row=n; row>=1; row--)
    {
        for(space=1; space<=n-row; space++)
        {
            printf("  ");
        }

        for(col=1; col<=2*row-1; col++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}