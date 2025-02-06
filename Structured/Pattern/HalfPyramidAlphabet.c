#include<stdio.h> 

int main() 
{
    int n, row, col; 
    char C = 'A';

    printf("Enter number of lines: ");
    scanf("%d", &n);

    printf("\n");

    
    for(row=1; row <= n; row++)
    {        
    
        for(col=1; col<=row; col++)
        {
            printf(" %c", C);
        }

        C++;

        printf("\n");
    }

    return 0;
}