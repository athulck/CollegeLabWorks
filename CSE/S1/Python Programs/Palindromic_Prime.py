#Palindromic Prime within a given range

#Function to check palindrome
def palindrome(n):
    temp=n
    dig=0
    while n>0:
        r=n%10
        dig=(10*dig)+r
        n//=10
    if temp==dig:
        return True
    else:
        return False
    
#Function to check prime
def prime(n):
    flag=True
    for i in range(2,n):
        if n%i == 0:
            flag=False
    return flag

#main()
low=int(input("Enter the lower limit : "))
high=int(input("Enter the upper limit : "))
for n in range(low,high+1):
    if n <= 1:
        continue
        #Since, 1 is neither prime nor composite
    elif palindrome(n) and prime(n):
        print ("{0} is a palindromic prime".format(n))
    else:
        continue
