
print("For 1st matrix : \n")
r1=list(input("Enter first row: "))
r2=list(input("Enter second row: "))
r3=list(input("Enter third row: "))
x=[r1,r2,r3]

print("For 2nd matrix : \n")
r1=list(input("Enter first row: "))
r2=list(input("Enter second row: "))
r3=list(input("Enter third row: "))
y=[r1,r2,r3]

sum_=[[0,0,0],[0,0,0],[0,0,0]]

for i in range(len(x)):
    for j in range(len(r1)):
        for k in range(len(r1)):
           sum_[i][j]+=x[i][k]*y[k][j]

for i in sum_:
    print i
      
