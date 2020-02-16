
import random as R

def gen_key(key_len = 128):

	key = ['0']*128
	for i in range(key_len):
		key[int(R.random()*1000)%128] = '1'

	key = ''.join(key)
	return key

def expand_key(key):

	expanded_key = list()
	chop_index = 0

	i = 0
	count = 0
	while(len(expanded_key) < 52):

		new_key = ''
		while (len(new_key) < 16):
			new_key = new_key + key[i%128]
			i = (i+1) % 128
		
		expanded_key.append(new_key)
		count += 1

		if (count == 8):
			count = 0
			i = (i + 25) % 128

	return expanded_key




def encrypt(plain_text=PT, rounds=17):

	key_i = 0

	for i in range(1, rounds+1):

		# Odd rounds
		if (i%2 != 0):



		else:
		# Even rounds


key = gen_key()

expanded_keys = expand_key(key)

print(len(expanded_keys))

