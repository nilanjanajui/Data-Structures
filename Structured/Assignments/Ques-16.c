#include <stdio.h>

int main() 
{
    int n, row, col, space;

    printf("How many rows for the hourglass?\n ");
    scanf("%d", &n);

    for (row=1; row<=n; row++) 
    {
        for (space=1; space<row; space++)
        {
            printf("  ");
        }
        for (col=1; col<=2*(n-row)+1; col++) 
        {
            printf("* ");
        }

        printf("\n");
    }

    for (row=n; row>= 1; row--) 
    {
        for (space = 1; space <row; space++) 
        {
            printf("  ");
        }
        for (col=1; col<=2*(n-row)+1; col++) 
        {
            printf("* ");
        }
        
        printf("\n");
    }

    return 0;
}
