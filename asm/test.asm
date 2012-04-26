;sg
;c:\emu8086\inc\0_com_template.txt
org 100h

mov cx,0500h
mov ds,cx
mov [0500h],0003h
mov al,[0500h]

ret




