def find (string,ch,pos):
    i=pos
    while(i<len(string)):
        if(string[i]==ch):
            return i
        i+=1
        continue
    return -1

string=raw_input("Enter the string : ")
ch=raw_input("Enter your search charecter : ")
pos=int(input("Enter the index (\"not position\") to start search : "))
r=find(string,ch,pos)
if r == -1:
    print "SorrY 404 Not Found !"
else:
    print("{0} found at index {1}".format(ch,r))
