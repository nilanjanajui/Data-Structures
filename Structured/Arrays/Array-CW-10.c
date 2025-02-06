#include <stdio.h>
#include <math.h>

int main() 
{
    int n, i;

    float sum=0, mean, squaredDiffSum=0, diff, variance;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    
    for (i = 0; i < n; i++) 
    {
        sum += arr[i];
    }
    
    mean = sum / n;

    for (i = 0; i < n; i++) 
    {
        diff = arr[i] - mean;
        squaredDiffSum += diff * diff;
    }


    variance = squaredDiffSum / n;

    printf("Variance of the elements: %.2f\n", variance);

    return 0;
}
