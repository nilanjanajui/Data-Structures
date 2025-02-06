#include<stdio.h>

int main()
{
    int x;
    printf("input the value for x: ");
    scanf("%d", &x);
    switch(x)
    {
        case 1: printf("one\n");
        case 2: printf("two\n");
        case 3: printf("three\n");
                break;
        case 4: printf("four\n");
        case 5: printf("five\n");        
    }
    
return 0;

}