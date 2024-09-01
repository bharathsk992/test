#include <stdio.h>
void biggest3()
{
        int A, B, C;

        printf("\nEnter the numbers A, B and C: ");
        scanf("%d %d %d", &A, &B, &C);

        // finding max using compound expressions
        if (A >= B && A >= C)
                printf("%d is the largest number.\n", A);

        else if (B >= A && B >= C)
                printf("%d is the largest number.\n", B);

        else
                printf("%d is the largest number.\n", C);

}
