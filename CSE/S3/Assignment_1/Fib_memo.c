/*
Stack -     1 2 3 4 5 6 7  8   9   10
Fib   -   	0 1 1 2 3 5 8  13  21  34
Terms - 	1 2 3 4 5 6 7  8   9   10
*/

//Correct upto 94 terms

#include <stdio.h>
#include <stdlib.h>

unsigned long long *MAP;
int top=2;

unsigned long long fib(unsigned long long n)
{
	if(top >= n) return MAP[n];
	else
	{
		unsigned long long b = fib(n-1);
		unsigned long long a = fib(n-2);
		MAP[++top] = a+b;
		return a+b;
	}
}

void main(int argc, char const *argv[])
{
	int n;
	printf("\nEnter the term number : ");
	scanf("%d",&n);
	MAP = (unsigned long long*)malloc(n*sizeof(unsigned long long));
	MAP[1]=0;
	MAP[2]=1; 
	printf("Ans : %llu\n",fib(n));
	printf("\n");
	for(int i=1;i<=top;i++) printf("%llu ",MAP[i]);
}