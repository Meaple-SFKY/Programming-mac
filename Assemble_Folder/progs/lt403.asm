;lt403.asm
	.model small
	.stack
	.data
_a	db ?
_b	db ?
_c	db ?
tag	db ?
	.code
	.startup
	mov al,_b
	imul al
	mov dx,ax
	mov al,_a
	imul _c
	mov cx,4
	imul cx
	cmp bx,ax
	jge yes
	mov tag,0
	jmp done
yes:	mov tag,1
done:	.exit 0
	end
