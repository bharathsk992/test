#include <stdio.h>
void biggnt()
{
         int n, i;
         float num, lg;
         clrscr();
         printf("How many numbers?\n");
         scanf("%d",&n);
         printf("Enter number-1: ");
         scanf("%f", &num);
         lg = num;
         i=2;
         while(i<=n)
         {
          printf("Enter number-%d: ",i);
          scanf("%f", &num);
          if(num>lg)
          {
           lg = num;
          }
          i++;
         }
         printf("\nLargest = %0.2f", lg);
         getch();
         // return(0);
}
