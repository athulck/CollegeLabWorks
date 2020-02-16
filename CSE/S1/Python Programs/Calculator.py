import random
import sys
import os

"""This is a calculator program"""

print "CALCULATOR\n"
print "1.Add \n2.Subtract \n3.Multiply \n4.Division"
option=input("Enter your choice : ")
a=input("Enter first number : ")
b=input("Enter second number : ")
ans=0.0
if (option == 1):
  ans=a+b
  print "The sum of ",a," and ",b," is ",ans

elif (option == 2):
  ans=a-b
  print "The difference of ",a," and ",b," is ",ans

elif (option == 3):
  ans=a*b
  print "The product of ",a," and ",b," is ",ans

elif (option == 4):
  ans=float(a//b)
  print "The quotient of ",a," and ",b," is ",ans

else:
  print "Invalid Input !!!"
