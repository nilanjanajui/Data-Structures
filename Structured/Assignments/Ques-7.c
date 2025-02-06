#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, H;

    scanf("%f %f", &a, &b);
    H=sqrt((pow(a,2))+(pow(b,2)));

    printf("%.2f\n", H);

return 0;

}