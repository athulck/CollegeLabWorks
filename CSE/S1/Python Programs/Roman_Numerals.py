#Program to convert decimals to roman numerals

a_1    = {0:"",1:"I",2:"II",3:"III",4:"IV",5:"V",6:"VI",7:"VII",8:"VIII",9:"IX"}
a_10   = {0:"",1:"X",2:"XX",3:"XXX",4:"XL",5:"L",6:"LX",7:"LXX",8:"LXXX",9:"XC"}
a_100  = {0:"",1:"C",2:"CC",3:"CCC",4:"CD",5:"D",6:"DC",7:"DCC",8:"DCCC",9:"CM"}
a_1000 = {0:"",1:"M",2:"MM",3:"MMM",4:"IV",5:"V",6:"VI",7:"VII",8:"VIII",9:"IX"}

n=int(input("Enter the number (1<n<400) : "))

temp=n
dig=list()
while(temp>0):
	rem=temp%10
	dig.append(rem)
	temp/=10
	
ans = list()
for i in dig[::-1]:
	ans.append(i)	

res=list()
l=len(ans)
for i in ans:
	if (l == 4):
		res.append(a_1000[i])
	if (l == 3):
		res.append(a_100[i])
	if (l == 2):
		res.append(a_10[i])
	if (l == 1):
		res.append(a_1[i])
	l-=1
	
print(''.join(res))
