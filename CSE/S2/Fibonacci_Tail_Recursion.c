//Fibonacci
#include<stdio.h>

int fibonacci(int n, int next, int result)
{
  if(n==1)
    return result;
  else
    return fibonacci(n-1,next+result,next);
}

void main()
{
  int n;
  printf("\nEnter the term number : ");
  scanf("%d", &n);

  printf("\n%d", fibonacci(n,1,0));
}


