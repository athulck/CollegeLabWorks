'''
dic=dict()
stri=raw_input("Enter your string : ")
for ch in stri:
    if ch not in dic:
        dic[ch]=1
    else:
        dic[ch]+=1

print dic
'''



eng = dict()
print eng
eng={1: "One",2: "Two",3: "Three",4: "Four"}
print eng
print eng[3]
print len(eng)
print 2 in eng
vals=eng.keys()
print (vals)
vals=eng.values()
print (vals)
vals=eng.items()
print (vals)
print eng.has_key(3)

print type(vals)
del eng[2]
print eng

