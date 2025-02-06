#include<stdio.h>

int main()
{
    int ar[5]={4,8, 15, 23, 42}, i;

    for(i=0; i<=4; i++)
    {
        if(ar[i]==23)
        {
            printf("Found.\n");
        }
        else
        {
            printf("Not Found.\n");
        }
    }
    return 0;

}