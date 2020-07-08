;lt405.asm
	.model small
	.stack
	.data
sum	dw ?
	.code
	.startup
	xor ax, ax
	mov cx,100
again:	add ax,cx
	loop again
	mov sum,ax
	.exit 0
	end
