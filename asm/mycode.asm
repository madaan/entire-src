;sg
;c:\emu8086\inc\0_com_template.txt
org 100h

data segment
    source db 'INDIA'
    desn db 5 dup(0)
data ends   

getmax macro a1,b,max                     
    copy source,desn,0005h;
      cmp a1,b
    ja a_is_larger
    b_is_larger
    mov max,b
    jmp outofhere
    a_is_larger:
    mov max,a1;
    outofhere:
endm

copy macro src,desn3,count
     lea si,src
     lea di,desn3
     mov cx,count;
     rep movsb
copy endm     

code segment
    assume cs:code,ds:data
    mov ax,data
    mov ds,ax                    
    mov es,ax
    getmax AX,BX,CX
code ends
ret




