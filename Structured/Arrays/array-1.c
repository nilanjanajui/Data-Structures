#include <stdio.h>



int main() 
{
    int i, n=5, item=10, loc;
    int data[6]={5,7,3,2,11};

    data[n+1]=item;
    loc=1;
    while(data[loc]!=item)
    {
        loc=loc+1;
    }

    if(loc==n)
    {
        loc=0;
    }

    printf("%d\n", loc);

    return 0;
}
