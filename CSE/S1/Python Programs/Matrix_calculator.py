#Matrix Calculator


def input_matrix():
    x=list()
    r=int(input("Enter number of rows : "))
    for i in range(0,r):
        a=list(input("Enter row {0} : ".format(i+1)))
        x.append(a)
    c=len(a)
    return (x,r,c)

def add_matrix():
    x,r1,c1=input_matrix()
    y,r2,c2=input_matrix()
    result=list()
    a=list()
    for i in range(c1):
        a.append(0)
    for i in range(r1):
        result.append(a)
    for i in result:
        print i
    if (r1 == r2) and (c1 == c2):
        for i in x:
            print i
        for i in y:
            print i
        print r1,c1
        for i in range(r1):
            for j in range(c1):
                result[i][j]=x[i][j]+y[i][j]
                print "\n",result[i][j]
        print ("The sum of matrices is : ")
        for i in range(0,r1):
            print ("\n")
            for j in range(0,c1):
                print ("result[{0}][{1}] : {2}".format(i,j,result[i][j]))
    else:
        print ("Matrices cannot be added ! ... Rows and columns does not match !")

print ("MENU")
print ("1.Addition")
print ("2.Subtraction")
print ("3.Multiplication")
print ("4.Transpose")
ch=int(input("Enter your choice : "))

if ch==1:
    add_matrix()
elif ch==2:
    sub_matrix()
elif ch==3:
    mul_matrix()
elif ch==4:
    trans_matrix()
else:
    raise KeyError("Invalid Input !")
