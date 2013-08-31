;sg
;c:\emu8086\inc\0_com_template.txt
org 100h

mov AX,0500h  ;init ds
mov DS,AX 
mov bp,0500h  
mov [0500h],05h ;init memory
mov [0501h],04h
mov [0502h],03h
mov [0503h],02h
mov [0504h],01h       
; START COMPARING FROM HERE
MOV [0505h],0504h; KEEP MAX INDEX IN MEMORY
;MOV [0507h],05h;
loop_outer:
MOV AL,[0500h] ;AX WILL STORE MAX
mov Bx,0501h 
mov si,0500h ; let it be max index
LOOP_INNER:
MOV DL,[Bx]   ;2ND NUMBER
CMP AL,DL     ; IS A<B i.e. DO WE NEED TO CHANGE MAX 
JB SWAP
JMP INNER_LOOP_REINIT
SWAP:
MOV AL,DL
MOV SI,Bx      ;SAVE THE INDEX TOO
INNER_LOOP_REINIT:
XOR DX,DX
MOV Dx,[0505h];
INC Bx
CMP Bx,DX
JBE LOOP_INNER
;INNER LOOP FINISHED , MAX FROM 0500 TO [0506] IS IN AX
;AND THE MAX INDEX IS IN SI
;SO EXCHANGE CONTENTS OF SI AND MAX_INDEX
MOV di,[0505h] ;what is the last index for this loop
MOV dl,[di]  ;save the value stored there
MOV [SI],Dl  ;where max number was stored,put dx
MOV [di],Al  ;store the max number

DEC di
mov [0505h],di  ;update last index for next time
mov cx,0501h
CMP di,cx

JAE loop_outer
hlt