#Program to swap two numbers with or without using a temporary variable

import sys
import os
import random

def swap_with_temp (a,b):
  temp=a
  a=b
  b=temp
  print "The value of a is ",a," and b is ",b

def swap_without_temp (a,b):
  a=a+b
  b=a-b
  a=a-b
  print "The value of a is ",a," and b is ",b

print "Program To Swap Two Numbers\n"
print "Press 1 to swap using temporary variable \nPress 2 to swap without using temporary variable"
option=input("Enter your choice : ")
a=input("Enter 1st number : ")
b=input("Enter 2nd number : ")

if (option == 1):
  swap_with_temp (a,b)
elif (option == 2):
  swap_without_temp (a,b)
else:
  print("Invalid Option")

