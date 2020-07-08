;lt401.asm
	.model small
	.stack
	.data
X	dw 5
Y	dw 6
Z	dw 7
W	dw ?
	.code
	.startup
	mov ax,X
	add ax,Y
	adc ax,Z
	mov W,ax
	.exit 0
	end
