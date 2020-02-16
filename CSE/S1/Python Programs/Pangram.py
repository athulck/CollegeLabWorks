#To check whether a given string is a pangram or not

string=raw_input("Enter your string : ")
dic=dict()
for i in string:
    if not i.isalpha():
        continue
    elif i == " ":
        continue
    elif i in dic:
        continue
    else :
        dic[i]=True
#print dic
if len(dic) == 26:
    print("The string is a pangram")
else:
    print("The string is not a pangram")
