

import random as R

def find_primitive_root(n):


	for i in range(2, n):

		lst = list()

		for j in range(0, 100):

			if ((i**j)%n) not in lst:
				lst.append( ((i**j)%n) )
			else:
				break

		count = 0
		for j in range(1, n):
			if j in lst:
				count+=1

		if (count == n-1):
			return i




class User(object):
	"""docstring for User"""
	def __init__(self, q):
		super(User, self).__init__()
		
		self.q = q
		alpha = find_primitive_root(self.q)
		print(alpha)

		self.X = R.choice( [x for x in range(1, self.q)] )
		self.Y = alpha**self.X % self.q


	def generate_key(self, Y):

		K = (Y**self.X) % self.q
		return K




userA = User(11)
userB = User(11)

print(userB.generate_key(userA.Y))
print(userA.generate_key(userB.Y))






