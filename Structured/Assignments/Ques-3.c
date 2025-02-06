#include<stdio.h>

int main()
{
    float F, C;

    printf("Enter the value in Fahrenheit scale: ");
    scanf("%f", &F);

    C = (F-32)*5/9;

    printf("%.2f\n", C);

return 0;

}