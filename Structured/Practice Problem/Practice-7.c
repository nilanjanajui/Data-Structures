#include<stdio.h>

int main()
{
    int ingredient;
    int i;
    double price[10];
    double weights[10];
    double cost = 0;

    scanf("%d\n", &ingredient);

    for(i=0; i<ingredient; i++)
    {
        scanf("%lf\n", &weights[i]);
    }
    for(i=0; i<ingredient; i++)
    {
        scanf("%lf", &price[i]);
    }
    for(i=0; i<ingredient; i++)
    {
        cost = cost+(price[i]*weights[i]);
    }
    printf("%.6lf\n", cost);

return 0;

}