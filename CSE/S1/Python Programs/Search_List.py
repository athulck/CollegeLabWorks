
def sel_sort(lis):
    l=len(lis)
    for i in range(l):
        small=i
        for j in range(i+1,l):
            if lis[i]>lis[j]:
                small=j
        if i != small:
            lis[i],lis[small]=lis[small],lis[i]
    print lis
    return lis
            
def bub_sort(lis):
    l=len(lis)
    for j in range(l):
        for k in range(j+1,l):
            if lis[j]>lis[k]:
                lis[j],lis[k]=lis[k],lis[j]
        print lis
    return lis

def lin_search(num,lis):
    for i in range(len(lis)):
        if lis[i] == num:
            k=i+1
            break
        else:
            k=-1
    return k

def bin_search(num,lis):
    
    lis=bub_sort(lis)
    upp=len(lis)-1
    low=0
    k=-1
    while low<=upp:
        mid=(upp+low)//2
        if lis[mid]>num:
            upp=mid-1
        elif lis[mid]<num:
            low=mid+1
        else:
            k=mid+1
            break
    return k                  

lis=list(input("Enter the list : "))
num=int(input("Enter the element to search : "))

if lin_search(num,lis) >0:
    print("{0} found at {1} (Linear)".format(num,lin_search(num,lis)))
else :
    print "Not found"
if bin_search(num,lis) >0:
    print("{0} found at {1} (Binary)".format(num,lin_search(num,lis)))
else :
    print "Not found"
