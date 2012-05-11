;sg
;c:\emu8086\inc\0_com_template.txt
org 100h
mov ax,0500h
mov ds,ax
mov es,ax 
mov [0500h],1234h;
mov [0502h],1123h;
mov [0504h],0AAF1h;
mov [0506h],0aaa1h;
mov [0508h],01322h
mov ax,0aaa1h;
mov cx,0005h;
mov di,0500h  ;
cld
repne scasw
cmp cx,0000h
jne found
jmp not_found
found : 
mov al,05h
sub al,cl
not_found:
ret




