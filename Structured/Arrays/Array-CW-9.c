#include <stdio.h>

int main() 
{
    int n, i;
    float sum, mean;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    sum=0;

    for (i = 0; i < n; i++) 
    {
        sum += arr[i];
    }

    mean = sum / n;
    
    printf("Mean of the elements: %.2f\n", mean);
    
    float diffArr[n];
    for (int i = 0; i < n; i++) 
    {
        diffArr[i] = arr[i] - mean;
    }
    
    printf("Differences from the mean:\n");

    for (int i = 0; i < n; i++) 
    {
        printf("%.2f\n", diffArr[i]);
    }

    return 0;
}