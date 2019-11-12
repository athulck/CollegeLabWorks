
//Prime numbers within range

#include<stdio.h>
int i,j,flag,n,count=0;


int isPrime(int n) {

    for (int i=2; i<=n/2; i++) {

        if (n%i == 0)
            return 0;

    }
    return 1;
}

void main() {

    int n;

    printf("\nEnter the range : ");
    scanf("%d",&n);


    for (int i=2; i<=n ;i++) {

        if (isPrime(i))
            printf("\n%d", i);
    }

}
