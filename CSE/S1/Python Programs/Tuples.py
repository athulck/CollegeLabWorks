#Tuples

"""
lis=list(input("Enter a List : "))
tp=tuple(lis)
print tp
"""
cube=0
l=int(input("Enter a limit : "))
lis=list()
for i in range (1,l+1):
    cube=i**3
    lis.append(cube)
print lis
tp=tuple(lis)
print tp
