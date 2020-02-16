#Program to find the largest of three numbers

import sys
import os
import random

def find_large(a,b,c):
  if(a>b):
    max=a
  else:
    max=b

  if(max<c):
    max=c
  return max

print "This is a program to find the largest of three numbers \n"

a=input("Enter the first number  : ")
b=input("Enter the second number : ")
c=input("Enter the third number  : ")

print "The largest of the given three numbers is : ",find_large (a,b,c)