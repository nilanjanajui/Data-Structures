#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, J, N=100, K=51, ITEM, LA[100];

    for(i=0; i<100; i++)
    {
        LA[i]= rand()%1000;
    }
    ITEM= LA[K];

    for(J=K; J<=N-1; J++)
    {
        LA[J]=LA[J+1];
    }
    N=N-1;

    printf("ITEM %d deleted from position %d\n", ITEM, K);

    return 0;
}