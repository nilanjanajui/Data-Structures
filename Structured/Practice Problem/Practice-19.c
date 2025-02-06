#include<stdio.h>
#include<math.h>

int main()
{
    double v, s, t;

    printf("Enter the Velocity: ");
    scanf("%lf", &v);

    printf("Enter the time: ");
    scanf("%lf", &t);

    s=2*t*v;

    printf("Distance: %.2lf\n", s);

    return 0;
}