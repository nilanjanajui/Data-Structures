#include<stdio.h>
int main()
{
    int num, reminder;

    scanf("%d", &num);
    reminder = num % 2;
    
    if(reminder == 0)
    {
        printf("the number is even\n");
    }
    else
    {
        printf("the number is odd\n");
    }

return 0;
}
