;lt407.asm
	.model small
	.stack
	.data
string	db 'HeLLO,eveRyboDy !',0
	.code
	.startup
	mov bx,offset string
again:	mov al,[bx]
	or al,al
	jz done
	cmp al,'A'
	jb next
	cmp al,'Z'
	ja next
	or al,20h
	mov [bx],al
next:	inc bx
	jmp again
done:	.exit 0
	end
