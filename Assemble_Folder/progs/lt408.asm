;lt408.asm
	.model small
	.stack
	.data
array	db 56h,23h,37h,78h,0ffh,0,12h,99h,64h,0b0h
	db 78h,80h,23h,1,4,0fh,2ah,46h,32h,42h
count	equ ($-array)/type array
	.code
	.startup
	mov cx,count
	dec cx
outlp:	mov dx,cx
	mov bx,offset array
inlp:	mov al,[bx]
	cmp al,[bx+1]
	jna next
	xchg al,[bx+1]
	mov [bx],al
next:	inc bx
	dec dx
	jnz inlp
	loop outlp
	.exit 0
	end
