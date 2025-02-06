#include <stdio.h>

int main() 
{
    int row, col, n;
    int coefficient = 1;
    
    printf("How many rows of Pascal's triangle?\n");
    scanf("%d", &n);


    for (row=1; row<=n; row++) 
    {
        
        for (col=1; col<= n - row - 1; col++)
        {
            printf(" ");
        }
        
        for (col=0; col<=row; col++) {
            printf("%d ", coefficient);
            coefficient = coefficient * (row - col) / (col + 1);
        }

        printf("\n");
    }

    return 0;
}
