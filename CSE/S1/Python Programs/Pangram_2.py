def linear(phrase):
    alphabet="abcdefghijklmnopqrstuvwxyz"
    stack=""
    for char in phrase:
        if char in alphabet:
            stack+=char
        
    for char in alphabet:
        if char not in phrase:
            return False
    return True

phrase=raw_input("Enter string : ")
if (linear(phrase)):
    print "pangram"
else:
    print " not pangram"
