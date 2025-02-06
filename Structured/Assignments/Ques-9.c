#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c, D, x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);

    D=(b*b)-(4*a*c);
    

    x1=(-b+sqrt(D))/(2*a);
    x2=(-b-sqrt(D))/(2*a);
    
    printf("%.2lf\n", x1);
    printf("%.2lf\n", x2);

return 0;

}