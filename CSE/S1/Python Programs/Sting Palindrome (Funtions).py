def fib(n):
    if n<=1:
        return n
    else:
        return fib(n-1)+fib(n-2)

n=int(input("Enter the limit : "))
for i in range(0,n+3):
    if fib(i)>n:
       num=i-1
       break

for i in range(0,num+1):
    print (fib(i))
