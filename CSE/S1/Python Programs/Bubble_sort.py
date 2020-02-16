# Bubble Sort

def bubble_sort (lst):
    l=len(lst)
    for i in range(0,l):
        print ("Loop {0}".format(i+1))
        for j in range(0,l-1):
            if lst[j+1]<lst[j]:
                #swapping
                lst[j+1],lst[j]=lst[j],lst[j+1]
            print lst
        print lst
    return lst



lst=list(input("Enter the list : "))
lst=bubble_sort(lst)
print ("The final result is : ")
print lst

#Give this as sample input : 1,9,7,8,6,5,4,2,3
