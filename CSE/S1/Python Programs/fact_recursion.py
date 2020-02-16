def fact_recu(n):
    if n == 1:
        return 1
    else :
        return n*fact_recu(n-1)

n=int(input("Enter number : "))
print (fact_recu(n))
