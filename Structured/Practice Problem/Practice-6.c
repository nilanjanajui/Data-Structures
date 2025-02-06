#include <stdio.h>

int main(void)
{
    int nbBoxCars, carNumber;
    double weights[50];
    double totalWeight = 0.0;
    double averageWeight;
    
    scanf("%d\n",&nbBoxCars);
    for (carNumber = 0; carNumber < nbBoxCars; carNumber = carNumber + 1)
    {
        scanf("%lf",&weights[carNumber]);
        totalWeight = totalWeight + weights[carNumber];
    }

    averageWeight = totalWeight / nbBoxCars;

    for (carNumber = 0; carNumber < nbBoxCars; carNumber = carNumber + 1)
    {
        printf("%.1lf\n",averageWeight - weights[carNumber]);
    }
return 0;

}