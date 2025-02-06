#include<stdio.h>
#include<math.h>

int main()
{
    float r, A;
    printf("Enter the value of radius: ");
    scanf("%f", &r);
    
    A= 3.14*r*r;
    printf("The value of area is: %.2f\n", A);

return 0;

}