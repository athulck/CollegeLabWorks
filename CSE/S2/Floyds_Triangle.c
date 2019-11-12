//Floyd's Triangle
#include<stdio.h>

void main() {

    int n, k=1;

    printf("\nEnter number of lines/rows : ");
    scanf("%d", &n);
    printf("\n");

    //Loop for keeping track of the number of lines
    for(int i=0; i<n; i++) {

        for (int j=0; j<=i; j++) {

            printf("%d\t",k);
            k++;
        }
        printf("\n");
    }

}
