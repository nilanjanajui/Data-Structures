#include<stdio.h>

int main()
{
    int i, n, sum;

    sum=0;
    
    for(i=100; i<=200; i++) {
        if(i%17==0)
        {
            sum=sum+i;
        } 
    }

    printf("Sum is: %d\n", sum);

    return 0;
}