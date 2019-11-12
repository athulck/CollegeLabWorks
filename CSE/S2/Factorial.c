
//Program to find factorial using tail recursion
#include <stdio.h>

int factorial(int n) {

	if (n <= 1)
		return 1;
	else
		return (n*factorial(n-1));
}

void main() {

	int n;
	printf("\nEnter the number : ");
	scanf("%d", &n);

	n = (n < 0) ? -1*n : n;
	printf("\nThe factorial of %d is : %d\n", n, factorial(n));
}
