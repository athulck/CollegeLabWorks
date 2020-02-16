

def gcd(a, b):

	a = abs(a)
	b = abs(b)
	if (b > a):
		(a, b) = (b, a)

	# print("GCD({0}, {1})".format(a, b))
	if (b == 0):
		return a

	return gcd(b, a%b)



def find_inverse_mod(b, m, verbose = False):

	array1 = [0, 1, 0, m, 0, 1, b]
	array2 = list()

	if(verbose): 
		print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}".format('Q', 'A1', 'A2', 'A3', 'B1', 'B2', 'B3'))
		print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}".format(*tuple(array1)))

	while (True):

		Q = array1[3]/array1[6]
		array2.append(Q)
		array2.append(array1[4])
		array2.append(array1[5])
		array2.append(array1[6])

		array2.append(array1[1] - Q*array1[4])
		array2.append(array1[2] - Q*array1[5])
		array2.append(array1[3] - Q*array1[6])

		if(verbose): print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}".format( *tuple(array2) ))

		if (array2[6] == 1):
			return array2[5]
		elif (array2[6] == 0):
			return array2[3]

		(array1, array2) = (array2, list())





class RSA(object):
	
	"""docstring for RSA"""
	def __init__(self, p, q):
		super(RSA, self).__init__()
		
		self.p = p
		self.q = q
		assert (p != q)
		assert (gcd(p, q) == 1)

		N = self.p * self.q

		# Totient(p, q) = (p-1)(q-1)
		N_totient = (self.p-1)*(self.q-1)

		for i in range(2, N_totient):
			if (gcd(N_totient, i) == 1):
				e = 7
				break;

		self.pub_key = (e, N)

		d = find_inverse_mod(e, N_totient)

		self.pvt_key = (d, N)

		print {"pub_key": self.pub_key, "pvt_key": self.pvt_key}
	

	def get_key(self):
		return {"pub_key": self.pub_key}

	def encrypt(self, M):
		e, N = self.pub_key 
		C = (M**e) % N
		return C

	def decrypt(self, C):
		d, N = self.pvt_key
		M = (C**d) % N
		return M
		


rsa = RSA(p=17, q=11)

print(rsa.encrypt(15))
print(rsa.decrypt(rsa.encrypt(15)))
