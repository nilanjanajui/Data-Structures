#include<stdio.h>

int main()
{
    int n, row, col;

    printf("How many rows of square?\n");
    scanf("%d", &n);

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n; col++)
        {
            if(row==col || row==1 || row==n)
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