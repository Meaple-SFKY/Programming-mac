;lt409.asm
	.model small
	.stack
	.data
string	db 'Let us have a try !','$'
	.code
	.startup
	mov si,offset string
outlp:	cmp byte ptr [si],'$'
	jz done
	cmp byte ptr [si],' '
	jnz next
	mov di,si
inlp:	inc di
	mov al,[di]
	mov [di-1],al
	cmp byte ptr [di],'$'
	jnz inlp
	jmp outlp
next:	inc si
	jmp outlp
done:	.exit 0
	end
