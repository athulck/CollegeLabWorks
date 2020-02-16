#Caesar Cipher

plain_txt=raw_input("Enter the plain text : ")
k=int(input("Enter the key : "))
cipher_txt=""

for i in plain_txt:
    c=ord(i)+k
    if c>ord('z'):
        cipher_txt+=chr(ord('a')+(c-ord('z'))-1)
    else:
        cipher_txt+=chr(c)

print ("The encrypted text is : {0}".format(cipher_txt))

plain_txt=""
for i in cipher_txt:
    c=ord(i)-k
    if c<ord('a'):
        plain_txt+=chr(ord('z')-(ord('a')-c-1))
    else:
        plain_txt+=chr(c)


print ("The decrypted text is : {0}".format(plain_txt))
