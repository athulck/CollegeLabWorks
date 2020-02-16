#Selection Sort

def sel_sort(a):
    n=len(a)
    for i in range(0,n):
        small = i

        #After running this loop, we'll have the index of the smallest element in the list
        for j in range(i+1,n):
            if a[small] > a[j] :
                small = j
        #Now, small has the index of the smallest element in the list

        #If small has changed, it means that the above mentioned loop found an element which is smaller than the currently selected element (i)
        #In that case, we are swapping and thus sorting the elements
                
        if small !=i:
            a[i],a[small]=a[small],a[i]

def main():
    a=[1,30,6,2,5,4,3,23,35,7]
    sel_sort(a)
    print a 

main()


""" ***Tips***
    It is easy to run both the for loops till 'n'.
    Do not use the value in 'j' for swapping, instead use the value in 'small'  
"""
