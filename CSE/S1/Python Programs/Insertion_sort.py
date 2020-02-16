#Insertion Sort

def insertion_sort(lst):
    for index in range(1,len(lst)):
        current_value=lst[index]
        position=index
        while position>0 and lst[position-1]>current_value:
            lst[position]=lst[position-1]
            position-=1
        lst[position]=current_value
        print lst
    return lst

lst=list(input("Enter your list of numbers : "))
lst=insertion_sort(lst)
print lst
