;sg
;c:\emu8086\inc\0_com_template.txt
org 100h

stack_1 segment 
    dw 4 dup(0)
    stack_top label word;
    stack_1 ends
main segment
    assume cs:main,ss:stack_1
    mov ax,stack_1
    mov ss,ax
    lea sp,stack_top
    pushf
    POP cx          
    main ends
hlt




                                           