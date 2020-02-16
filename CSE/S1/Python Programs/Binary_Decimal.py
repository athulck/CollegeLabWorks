def bin_dec(binary):
    l=len(binary)-1
    dec=0
    for i in binary:
        dec+=(2**l)*int(i)
        l-=1
    return dec

def dec_bin(dec):
    binary=""
    while True:
        r=dec%2
        q=dec/2
        if dec==1:
            binary=str('1')+binary
            break
        binary=str(r)+binary
        dec=q
    return binary

#binary=raw_input("Enter the binary : ")
dec = int(input("Enter decimal : "))

print dec_bin(dec)   
