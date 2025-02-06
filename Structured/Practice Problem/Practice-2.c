#include<stdio.h>

int main()
{
    int a;
    int b;
    int sum;

    scanf("%d\n", &a);
    scanf("%d", &b);

    sum = a+b;
    if(sum>=10)
    {
        printf("Special tax\n36", sum);
    }
    else{
        printf("Regular tax\n%d\n", sum*2);
    }

return 0;

}