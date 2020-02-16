

def CC_encrypt(plain_text, key):
	
	plain_text = plain_text.lower()
	
	alphabets = list()
	for i in range(97, 123):
		alphabets.append(chr(i))

	cipher_text = str()
	for i in plain_text:
		
		if (i == ' '):
			cipher_text = cipher_text + ' '
			continue

		index = (alphabets.index(i) + key)%26
		cipher_text = cipher_text + alphabets[index]

	return cipher_text

def CC_decrypt(cipher_text, key):
	
	cipher_text = cipher_text.lower()
	
	alphabets = list()
	for i in range(97, 123):
		alphabets.append(chr(i))

	plain_text = str()
	for i in cipher_text:
		
		if (i == ' '):
			plain_text = plain_text + ' '
			continue

		index = alphabets.index(i) - key
		if (index < 0):
			index = 26 + index

		plain_text = plain_text + alphabets[index]

	return plain_text




def CC_bruteforce (cipher_text):

	cipher_text = cipher_text.lower()

	print('\n\nBruteforcing ... \n')

	for key in range(0, 26):
		print("Key: ", key, "Plain Text : ", CC_decrypt(cipher_text, key))




print(" ***** Caesar Cipher Encryption ***** ")

plain_text = input("Enter the plain text : ")
key = int(input("Enter the key : "))
key = key % 26

print("Plain Text  : ", CC_decrypt( CC_encrypt(plain_text, key), key))
print("Cipher Text : ", CC_encrypt(plain_text, key))


#CC_bruteforce(CC_encrypt(plain_text, key))
