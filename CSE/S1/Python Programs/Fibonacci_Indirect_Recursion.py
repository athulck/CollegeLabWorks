#Fibonacci using Indirect Recursion

import time
start=time.clock()

def fib2(n):
    if n <= 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fib2(n-1)+fib1(n-2)    

def fib1(n):
    if n <= 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fib1(n-1)+fib2(n-2)
        

n=34

c=fib1(n)
print c
stop=time.clock()
print (stop-start)
