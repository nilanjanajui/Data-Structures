#include<stdio.h>

int main()
{
    int disp[2][3];
    int i, j;
    for (i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Enter value for disp [%d][%d]: ", i, j);
            scanf("%d", &disp[i][j]);
        }
    }
    printf("Two dimensional array element: \n");

    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ", disp[i][j]);
        }
        printf("\n");

    }  
    return 0;
}