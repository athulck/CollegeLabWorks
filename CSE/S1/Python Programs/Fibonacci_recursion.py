#Fibonacci using recursion
#Fibonacci series : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ...
#         Terms   : 1  2  3  4  5  6  7  8   9   10  11

#Calculating higher fibonacci series terms using MEMOIZATION

#from functools import lru_cache
#lru_cache -> Least Recently Used Cache
#@lru_cache(maxsize=1000)

def fibonacci(n):
    if type(n) != int:
        raise TypeError("Invalid Type Error !")
    elif n < 0:
        raise ValueError("Invalid Value Error !")
    elif n in fibonacci_cache:
        return fibonacci_cache[n]
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else :
        return fibonacci(n-1)+fibonacci(n-2)

fibonacci_cache={}

for n in range(1,101):
    if n not in fibonacci_cache:
        value=fibonacci(n)
        fibonacci_cache[n]=value
    print (n, ":", value)

#print fibonacci_cache
