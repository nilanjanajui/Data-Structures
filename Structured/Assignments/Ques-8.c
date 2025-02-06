#include<stdio.h>
#include<math.h>

int main()
{
    float x, M, Y;

    scanf("%f", &x);
    M=(x-1)/x;
    Y=M+(M*M)/2+(M*M*M)/3+(M*M*M*M)/4;

    printf("%.2f\n", Y);

return 0;

}