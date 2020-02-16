
#Program to check whether a given number is Adam's number or not

def reverse(n):
    rev=0
    while n>0:
        r = n%10
        rev = (10*rev)+r
        n /= 10
    return rev



n = int(input("Enter your number : "))           #103
n_sq = n**2       #10609

revr = reverse(n)       #301
revr_sq = revr**2       #90601

if (reverse(revr_sq) == n_sq):
    print ("The number {0} is Adam's Number ! ".format(n))
else:
    print ("The number {0} is not an Adam's Number ! ".format(n))
