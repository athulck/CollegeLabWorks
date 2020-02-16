#Python and randomness

import random

'''
for i in range(10):
    print 3+3*random.random()    
'''

for i in range(10):
    print random.uniform(3,7)

for i in range(10):
    print random.randint(1,6)

l=('Rock','Paper','Sissos')
for i in range(10):
    print random.choice(l)
