#Program to learn sockets

import socket
import threading
from queue import Queue

print_lock = threading.Lock()

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = '192.168.1.6'

def port_scan(port):
	try:
		s.connect((server,port))
		return True
	except:
		return False


for i in range(1,100):
	if port_scan(i):
		print ('Port'+i+'is open !')