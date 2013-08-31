;sg
;c:\emu8086\inc\0_com_template.txt
org 100h

init macro a
    mov ax,a
    mov bx,a
    mov cx,a
    mov dx,a
endm
code segment
    assume cs:code
    init 1
    init 2

ret




