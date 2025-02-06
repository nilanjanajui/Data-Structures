#include<stdio.h>
#include<math.h>

int main()
{
    int A,B, Add, Subs, Multi, Div;

    scanf("%d %d", &A, &B);

    Add=A+B;
    Subs=A-B;
    Multi=A*B;
    Div=A/B;

    printf("\n%d\n%d\n%d\n%d\n", Add, Subs, Multi, Div);
    
return 0;

}