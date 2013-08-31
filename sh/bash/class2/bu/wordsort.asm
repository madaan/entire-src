;sg
;c:\emu8086\inc\0_com_template.txt
org 100h 

mov ax,0500h
mov ds,ax 
mov [0500h],1234h;
mov [0502h],1123h;
mov [0504h],0AAF1h;
mov [0506h],0aaa1h;
mov [0508h],01322h
mov si,0004h;
loop_out:
mov bx,0500h;
mov cx,si;
loop_in:
mov ax,[bx]
mov dx,[bx+2]
cmp ax,dx
ja swap
jmp loop_re
swap:
mov [bx+2],ax
mov [bx],dx
loop_re:
add bx,0002h;
loop loop_in
dec si
jnz loop_out
 

ret




