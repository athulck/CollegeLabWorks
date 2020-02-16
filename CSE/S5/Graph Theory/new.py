

class Graph:

	def __init__(self, n):
		
		self.graph = dict()

		for i in range(n):
			print('Edges from vertex ',i , 'connects to vertex v with weight w (v, w) are : ')
			self.graph[i] = list(input())
		
		print(self.graph)



G = Graph(4)

