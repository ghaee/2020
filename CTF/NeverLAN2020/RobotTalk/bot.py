from pwn import *
import base64
host, port = 'challenges.neverlanctf.com', 1120
s = connect(host,port)
for i in range(5):
	s.recvuntil('decrypt: ')
	decrypt = s.recv(64)		
	print(decrypt)
	d = b64d(decrypt)
	print(d)
	s.send(d)
response = s.recv()
print(response)
s.close
