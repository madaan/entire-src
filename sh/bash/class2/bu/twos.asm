;sg
;c:\emu8086\inc\0_com_template.txt
org 100h

mov cx,0500h
mov di,0505h
mov ds,cx
mov cx,0005h
mov bx,0500h
HERE:
MOV AL,[BX]
NEG AL
MOV [DI],AL
INC DI
INC BX 
LOOP HERE

ret




