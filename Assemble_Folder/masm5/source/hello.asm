;完整段修正版
assume cs:code,ds:data,ss:stack
 
data segment
	str db 'Hello World!',10,13,'$'
data ends
;添加了堆栈段
stack segment stack
	db 32 dup(?)
stack ends
 
code segment
start:
	mov ax,data
	mov ds,ax
	lea dx,str
	mov ah,9
	int 21h
 
	mov ah,4ch
	int 21h
code ends
end start