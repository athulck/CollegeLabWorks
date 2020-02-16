



def gcd(a, b):

	a = abs(a)
	b = abs(b)
	if (b > a):
		(a, b) = (b, a)

	print("GCD({0}, {1})".format(a, b))

	if (b == 0):
		return a

	return gcd(b, a%b)



#print ("Ans : ", gcd(1066, 1970))





def EXTENDED_EUCLID(b, m):


	print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}".format('Q', 'A1', 'A2', 'A3', 'B1', 'B2', 'B3'))


	array1 = [0, 1, 0, m, 0, 1, b]
	print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}".format( *tuple(array1) ))
	array2 = list()

	while (True):

		Q = array1[3]/array1[6]
		array2.append(Q)
		array2.append(array1[4])
		array2.append(array1[5])
		array2.append(array1[6])

		array2.append(array1[1] - Q*array1[4])
		array2.append(array1[2] - Q*array1[5])
		array2.append(array1[3] - Q*array1[6])

		print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}".format( *tuple(array2) ))

		if (array2[6] == 1):
			return array2[5]
		elif (array2[6] == 0):
			return array2[3]

		(array1, array2) = (array2, list())



print( EXTENDED_EUCLID(550, 1759) )
