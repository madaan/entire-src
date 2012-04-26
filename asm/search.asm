;sg
;c:\emu8086\inc\0_com_template.txt
org 100h    

mov dx,0500h
mov ds,dx
mov es,dx ; 
mov di,dx ;required by scas
;load values
mov cx,000Ah ;the number of chars in string
mov AL,01h ;the test
REPNE SCASB
CMP CX,0000H
JNE CALC
MOV AL,00H
jmp end
CALC:
MOV AL,09H
SUB AL,CL 
end:   

ret




