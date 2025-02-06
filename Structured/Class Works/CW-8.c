#include<stdio.h>

int main()
{
    int M, P, C, T, TinMP;
    scanf("%d %d %d", &M, &P, &C);
    T=M+P+C;
    TinMP=M+P;
    if(M>=60 && P>=50 && C>=40 && T>=200 || TinMP>=150) { 
        printf("Eligible\n");
    }
    else {
        printf("Not Eligible\n");
    }
    
return 0;

}