#include<stdio.h>

int main()
{
    int age;
    int weight;
    int price;
    scanf("%d %d", &age, &weight);

    if(age<10) {
        price = 5;
    }
    else if(age ==60) {
        price = 0;
    }
    else {
        price = 30;
        if(weight>20) {
            price = price+10;
        }
    }
    printf("%d\n", price);

return 0;

}