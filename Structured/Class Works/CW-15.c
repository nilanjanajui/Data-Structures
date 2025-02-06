#include<stdio.h>

int main()
{
    int i, n, fact=1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if(n<0) {
        printf("\nError! Factorial of a negative number dowsn't exist.\n");
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            fact=fact*i;
        }
        printf("Factorial of %d = %d\n", n, fact);
    }
    return 0;
}