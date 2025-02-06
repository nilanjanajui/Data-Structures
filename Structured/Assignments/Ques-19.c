#include <stdio.h>

int main() 
{
    int n, row, col, space;

    printf("How many rows for the hollow pattern diamond?\n");
    scanf("%d", &n);

    for (row=1; row<=n; row++) 
    {
        for (space=1; space<=n-row; space++) 
        {
            printf("  ");
        }
        for (col=1; col<=2*row-1; col++) 
        {
            if (col==1 || col==2*row-1) 
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

    for (row=n; row>= 1; row--) 
    {
        for (space=1; space <=n-row; space++) 
        {
            printf("  ");
        }
        for (col=1; col<=2*row-1; col++) 
        {
            if (col==1 || col==2*row-1) 
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
