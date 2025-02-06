#include<stdio.h>

int main()
{
    int n=5;
    int i=1;
    while(i<=10){
        printf("%dx%d=%d\n", n, i, n*i);
        i=i+1;
    }

    return 0;
}