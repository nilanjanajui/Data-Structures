#include<stdio.h>
#include<math.h>

int main()
{
    float units, Bill;
    scanf("%f", &units);

    if(units<=200) 
    {
        Bill=units*0.8;
        printf("%.2f\n", Bill);
    }

    else if(units>200 && units<=300)
    {
        Bill=(units*0.8)+((units-200)*0.9);
        printf("%.2f\n", Bill);
    }

    else 
    {
        Bill= (units*0.8)+((units-200)*0.9)+((units-300)*1);
        printf("%.2f\n", Bill);
    }
    
    Bill=Bill+100;
    
    if(Bill>400)
    {
        Bill=Bill+(Bill*0.15);
        printf("%.2f\n", Bill);
    }

    else 
    {
        Bill=Bill;
        printf("%.2f\n", Bill);
    }
    
return 0;

}