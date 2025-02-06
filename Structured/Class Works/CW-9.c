#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, D, E, x1, x2;
    scanf("%f %f %f", &a, &b, &c);

    E=(b*b)-(4*a*c);
    D= sqrt(E);
    x1=-b+(D/(2*a));
    x2=-b-(D/(2*a));

    if(a==0 && b==0) {
        printf("No Solution.\n");
    }
    else if(a==0) {
        printf("There is only one root.\n");
    }
    else if(E<0)
    {
        printf("There is no real roots.\n");
    }
    else {
        printf("There are two real roots.\n");
    }

return 0;

}