;lt406.asm
	.model small
	.stack
	.data
wordX	dw 56
byteY	db ?
	.code
	.startup
	mov ax,wordX
	mov cx,16
	mov dl,-1
again:	inc dl
	test ax,1
	ror ax,1
	loope again
	je  notfound
	mov byteY,dl
	jmp done
notfound:	mov byteY,-1
done:	.exit 0
	end
