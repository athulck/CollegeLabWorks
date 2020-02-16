#Picking

import pickle


dic={'Rice':5, 'Wheat':5, 'Sugar':1}
string="Ithreyum pooyi vaangitt vaa manushyaa!"
n=9895070968
lst=['KR',2,4.5]
tple=(1,2,3,5,6,7,0)

f=open("file_pck.txt","wb")
f.write(str(dic)+"\n")
f.write(string+"\n")
f.write(str(n)+"\n")
f.write(str(lst)+"\n")
f.write(str(tple)+"\n")
f.close()

f=open("file_pck.txt","rb")
for i in range(5):
    yo=f.readline()
    print type(yo), ":", yo
f.close()
