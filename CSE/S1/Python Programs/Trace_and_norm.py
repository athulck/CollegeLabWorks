#Trace and Norm of a matrix

a=list(input("Enter first row : "))
b=list(input("Enter second row : "))
c=list(input("Enter third row : "))

x=[a,b,c]
sum_1,sum_2=0,0
for i in range(3):
    for j in range(3):
        if i == j:
            sum_1+=x[i][j]
            sum_2+=(x[i][j]**2)

print ("Trace of the given matrix is : {0}".format(sum_1))
print ("Norm of the given matrix is : {0}".format(sum_2))
