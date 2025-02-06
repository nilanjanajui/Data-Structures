#include<stdio.h>

int main()
{
   int array[10];
   int ingradientID;
   int i;
   for (i=0; i<10; i++) 
   {
    scanf("%d\n", &array[i]);

   }
   scanf("%d", &ingradientID);
   if(ingradientID<10) 
   {
        printf("%d\n", array[ingradientID]);
   }
   else{
      printf("Invalid IngradientID.\n");
   }

return 0;

}