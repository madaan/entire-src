;sg
;c:\emu8086\inc\0_com_template.txt
org 100h
data segment
    password db 'FAILSAFE'
    str_len equ ($-password)   
    input db 'FAILSAAE'
data ends
main segment
       assume cs:main,ds:data,es:data
       mov ax,data
       mov ds,ax
       mov es,ax
       lea si,password
       lea di,input 
       mov cx,str_len
       mov dx,199
       cld
       repe cmpsb
       jne ue;
       jmp e;
       e: 
       mov al,0ffh 
       out dx,al
       jmp ok
       ue:        
       mov al,00h
       out dx,al 
       ok:
main ends
hlt




