#include<stdio.h>

int main()
{
    int lb=0, ub=7, item, loc, beg, end, mid;
    int data[8] = {6, 13, 14, 25, 33, 43, 51, 53};
    beg=lb;
    end=ub;
    mid= ((beg+end)/2);
    printf("Enter item: ");
    scanf("%d", &item);

    while(beg<=end && data[mid]!=item)
    {
        if(item<data[mid]) 
    {
        end=mid-1;
    }
    else
    {
        beg=mid+1;
    }

        mid= ((beg+end)/2);
    }

    if(data[mid]==item)
    {
        loc=mid;
        printf("%d\n", loc);
    }
    else
    {
        loc=0;
        printf("Not found!");
    }
    
    return 0;

}