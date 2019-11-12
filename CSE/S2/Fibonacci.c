//Fibonacci Series
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int terms;
    printf("\nEnter number of terms : ");
    scanf("%d", &terms);

    if(terms <= 0) {
        printf("\nPlease enter a positive number !\n");
        exit(0);
    }

    int a=0, b=1;
    switch (terms) {
        case 1: printf("0\n");
                break;
        case 2: printf("0\n");
                printf("1\n");
                break;
        default:printf("0\n");
                printf("1\n");
                for (int n=0, c=a+b; n<(terms-2) ; a=b, b=c, c=a+b, n++) 
                    printf("%d\n", c);
    }
}