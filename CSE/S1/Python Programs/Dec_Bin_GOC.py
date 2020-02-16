
def bin_to_dec(binary):
    l=len(binary)-1
    dec=0
    for i in binary:
        dec+=(2**l)*(int(i))
        l-=1
    return dec

def dec_to_bin(dec):
    binary=""
    while(dec>0):
        r=dec%2
        dec//=2
        binary=str(r)+binary
    return binary


bin_str=raw_input("Enter the binary numbers : ")
binary=""
lst=list()
for i in bin_str:
    if i == ",":
        dec=bin_to_dec(binary)
        if dec % 5 == 0:
            binary=dec_to_bin(dec)
            lst.append(binary)
        binary=""
        continue
    else:
        binary+=i

print lst
