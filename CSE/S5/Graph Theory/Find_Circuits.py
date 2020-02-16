

# Python program to print DFS traversal from a 
# given given graph 

# This class represents a directed graph using 
# adjacency list representation 



class Stack:

	def __init__(self):
		# stack
		self.stack = list()
		self.stack_top = -1

	def push(self, item):
		self.stack.append(item)
		self.stack_top += 1
		 

	def pop(self):
		if(self.stack_top < 0):
			return None
		item = self.stack[self.stack_top]
		self.stack_top -= 1
		return item

	def print_stack(self):
		print("Stack : ")
		for i in range(self.stack_top+1):
			print(i)

	def gimme_the_stack(self):
		return self.stack


class Graph: 

	# Constructor 
	def __init__(self, n, x): 

		# a dictionary to store the graph 
		self.graph = dict()
		# a list to know if the vertices are visited or not
		self.n = n
		self.x = x
		self.visited = [False]*self.n
		self.stack = Stack()

	# function to add an edge to the graph 
	def add_edge(self,u,v):

		# if we want to add an edge to an old vertex
		if (u in self.graph):
			self.graph[u].append(v)
		# if there is a new vetrex involved
		else:
			self.graph[u] = [v]

	def DFS (self, v):

		self.visited[v] = True
		self.stack.push(v)

		for i in self.graph[v]:
			if(len(self.stack.gimme_the_stack()) <= 2):
				if (self.visited[i] == False):
					self.DFS(i)
			else:
				print(self.stack.gimme_the_stack(), i)




#Number of vertices
n = 4

# Create a graph given in the above diagram 
g = Graph(n,2) 

#Defining the adjacency matrix
#  vertices		0 1 2 3
adj_matrix = [ [0,1,1,0],
               [1,0,1,0],
               [1,1,0,1],
               [0,0,1,0] ]

for i in range(n):
	for j in range(n):
		if (adj_matrix[i][j] == 1):
			g.add_edge(i,j)
  

print(g.graph)
print ("Following is DFS from (starting from vertex 2)")
g.DFS(2)

print(g.stack.gimme_the_stack())










