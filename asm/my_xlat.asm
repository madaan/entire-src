;sg
;c:\emu8086\inc\0_com_template.txt
org 100h
         
  
    mov cx,0500h
    mov ds,cx
    mov cx,07h
    mov bx,0500h
    mov al,01h
    power:
    shl al,01h
    mov [bx],al
    inc bx
    loop power 
    mov bx,04ffh
    mov al,05
    xlat  ; al to 2^al+1
    
     

ret




