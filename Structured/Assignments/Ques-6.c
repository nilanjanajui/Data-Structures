#include<stdio.h>
#include<math.h>

int main()
{
    int X, Y, Z, Total, Average;

    scanf("%d %d %d", &X, &Y, &Z);

    Total=X+Y+Z;
    Average=Total/3;

    printf("%d\n%d\n", Total, Average);

return 0;

}