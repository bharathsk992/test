#include <stdio.h>
big3()
{
    int num1, num2, temp;
    
    num1=20,num2=30;
    if(num1 == num2)
        printf("Both are Equal\n");
    else{
        temp = num1 > num2? num1 : num2;
        printf("%d is largest",temp);
    }
  return 0;
}
