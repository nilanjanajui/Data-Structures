#include<stdio.h>
#include<math.h>

int main()
{
    float r, A, V;
    const float PI=3.14;

    scanf("%f", &r);

    A= 4*PI*r*r;
    V=(4*PI*r*r*r)/3;

    printf("%.2f\n%.2f\n", A, V);

return 0;

}