#Program to count the number of vowels

vowels=['a','e','i','o','u','A','E','I','O','U']
count=0
stri=raw_input("Enter the string : ")
for i in stri:
    for j in range(0,len(vowels)):
        if i == vowels[j]:
            count+=1

print ("The number of vowles is : {0}".format(count))
