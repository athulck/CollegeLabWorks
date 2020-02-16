#Program to check whether a number is prime or not

import time
import sys

n=int(input("Enter your number : "))
if n==1:
    print ("1 is neither prime nor composite")
    time.sleep(2)
    sys.exit(0) 
    
for i in range(2,n):
    if n%i==0:
        print ("{0} is not a prime number".format(n))
        time.sleep(2)
        sys.exit(0)

print ("{0} is a prime number".format(n))
