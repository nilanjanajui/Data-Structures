#include <stdio.h>

int main() 
{
    int n, row, col, number=1;

    printf("How many rows for Floyd's triangle?\n");
    scanf("%d", &n);

    for (row=1; row<=n; row++) 
    {
        for (col=1; col<=row; col++) 
        {
            printf("%d ", number);
            number++;
        }
        
        printf("\n");
    }

    return 0;
}
