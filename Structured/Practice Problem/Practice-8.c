#include<stdio.h>

int main()
{
    int citynumber;
    int polution;
    int count=0;
    int i;
    scanf("%d\n", &citynumber);

    for(i=0; i<citynumber; i++) 
    {
        scanf("%d", &polution);
    
            if(polution>10000)
            {
                count= count+1; 
            }
    }
       
     printf("%d\n", count);
    

return 0;
    
}