#include<stdio.h>

int main()
{
    int disp[2][2];
    int i, j;
    int trans[2][2];

    for (i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter value for disp [%d][%d]: ", i, j);
            scanf("%d", &disp[i][j]);
        }
    }
    printf("Two dimensional array element: \n");

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ", trans[i][j]);
        }

        printf("\n");

    } 

    return 0;
}