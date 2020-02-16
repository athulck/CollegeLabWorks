#Program to check whether a number is perfect or not

n=int(input("Enter your number : "))
sum=0
for i in range(1,n):
    if n%i==0:
        sum+=i

if sum==n:
    print ("{0} is a perfect number".format(n))
else:
    print ("{0} is not a perfect number".format(n))
