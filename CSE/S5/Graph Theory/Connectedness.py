
# Connectedness and components


class Graph: 

	# Constructor 
	def __init__(self, n): 

		# the graph 
		self.graph = list()

		for i in range(n):
			row = list()
			for j in range(n):
				print('Enter the weight of the edge (',i+1, ', ',j+1, ') : ')
				el = int(input())
				row.append(el)
			self.graph.append(row)


	def display(self):

		print("Graph : ")
		for row in self.graph:
			print(row)

	def fuse(self, i, j):

		# ith row = ith row OR jth row
		for k in range(len(self.graph)):
			self.graph[i][k] = self.graph[i][k] or self.graph[j][k]
		
		# remove the jth row
		self.graph.pop(j)

		# remove the jth column
		for k in range(len(self.graph)):
			self.graph[k].pop(j)


	def c_and_c():

		# pick a vertex i
		for i in range(len(self.graph)):

			for j in range(len(self.graph)):
				if(self.graph[i][j] == 1):
					fuse(i, j)





	

G = Graph(4)
G.fuse(1,3)
G.display()
