#include <stdio.h>

int main() {
    int i, sum;
    sum=0;

    for (i=101; i<200; i++) 
    {
        if (i % 7 == 0)
        {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}
