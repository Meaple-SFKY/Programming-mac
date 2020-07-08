;lt410.asm
	.model small
	.stack
	.data
srcmsg	db 'Try your best, why not.$'
dstmsg	db sizeof srcmsg dup(?)
	.code
	.startup
	mov ax,ds
	mov es,ax
	mov si,offset srcmsg
	mov di,offset dstmsg
	mov cx,lengthof srcmsg
	cld
	rep movsb
	mov ah,9
	mov dx,offset dstmsg 
	int 21h
	.exit 0
	end
