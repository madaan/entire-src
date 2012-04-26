
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;sg    
MOV CX,0500H
MOV DS,CX
MOV BX,[0004]
      
REP:
ADD AL,[BX]
DEC BX
JNZ REP
MOV [0000],AL
ENDS

ret




