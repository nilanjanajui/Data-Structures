
#include<stdio.h>

int main()
{
    int height;
    int leaflets;

    scanf("%d %d", &height, &leaflets);
    if(height>=10 && leaflets>=10) {
        printf("Calaelen\n"); 
        if(height<=8 && leaflets>=5) {
            printf("Falarion\n");
        }
    }

    else if(height<=5 && leaflets>=8) {
        printf("Tinuviel\n"); 
        if(height>=12 && leaflets>=7)
        {
            printf("Dorthonion\n");
        }
    }
    else {
        printf("Uncertain\n");
    }

return 0;
    
}
