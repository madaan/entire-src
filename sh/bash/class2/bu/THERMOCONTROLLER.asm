;sg
;c:\emu8086\inc\0_com_template.txt

#start=thermometer.exe#


#make_bin#

name "led"

org 100h

CHECK:
mov dx,125
IN AL,DX
CMP AL, 75
JBE TURN_ON
JMP TURN_OFF
TURN_ON:
IN AL,127
AND AL,01Fh
JZ ON
JMP CHECK
ON:
MOV DX,127
MOV AL,1
OUT DX,AX
MOV DX,9
MOV AL ,1
OUT DX,AL
JMP CHECK
TURN_OFF:
IN AL,127
AND AL,01Fh
JNZ OFF
JMP CHECK
OFF:
MOV DX,127
MOV AL,0
OUT DX,AX
MOV DX,9
MOV AL ,4
OUT DX,AL
JMP CHECK
ret




