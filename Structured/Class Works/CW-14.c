#include<stdio.h>

int main()
{
    int i, sum;

    sum=0;
    for(i=1; i<=10; i++)
    {
        sum+=i;
    }
    printf("sum is: %d\n", sum);

    return 0;

}