
#start=led_display.exe#
;sg
my_stack segment 
    dw 40 dup(0);
    
my_stack ends
main segment
assume cs:main,ss:my_stack
sub ax,ax 
mov dx,199
loop1:
out dx,ax
inc ax 
call kill_time
cmp ax,200
jbe loop1
hlt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;KILL TIME PROCEDURE (NEAR)
kill_time proc near
  push ax
  push bx
  push cx
  push dx
 ; mov bx,000fH
 ; loop_outer:
  ;mov ax,0001h
  ;loop_inner:         
  
  
  ;dec ax
  ;jnz loop_inner  
  ;dec bx
  ;jnz loop_outer
  ;end delay loop
  ;now pop registers back and return
  pop dx
  pop cx
  pop bx
  pop ax
  ret                               
kill_time endp                         
;;;;
main ends

    
;#make_bin#

;name "led"

;mov ax, 0001
;out 129, ax


hlt


