#include<stdio.h>

int main()
{
    float Inch, cm;

    printf("Enter the value in inch: ");

    scanf("%f", &Inch);
    
    cm=Inch*2.54;

    printf("%.2f\n", cm);

return 0;

}