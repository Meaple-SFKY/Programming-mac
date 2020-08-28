		.model	small
		.stack
		.data
strfir	db'Input the Hexadecimal:   ',0dh,0ah,'$'
strsec	db'The Decimal:             ',0dh,0ah,'$'
		.code
funfir	proc	far
start:	call	funsec
		call	demo
		call	funthi
		call	demo
		jmp		funfir
		ret
funfir	endp

funsec	proc	near
		mov		ax,	@data
		mov		ds,	ax
		mov		dx,	offset	strfir
		mov		ah,	09h
		int		21h
		mov		bx,	0
		mov		dx,	0
flagfi:	cmp		dx,	04h
		jz		exit
		mov		ah,	01h
		int		21h
		sub		al,	30h
		jl		exit
		cmp		al,	10d
		jl		flagse
		sub		al,	27h
		cmp		al,	0ah
		jl		exit
		cmp		al,	10h
		jge		exit
flagse:	mov		cl,	4
		shl		bx,	cl
		mov		ah,	0
		add		bx,	ax
		inc		dx
		jmp		flagfi
exit:	ret
funsec	endp

funthi	proc	near
		mov		ax,	@data
		mov		ds,	ax
		mov		dx,	offset	strsec
		mov		ah,	09h
		int		21h
		mov		cx,	10000d
		call	divi
		mov		cx,	1000d
		call	divi
		mov		cx,	100d
		call	divi
		mov		cx,	10d
		call	divi
		mov		cx,	1d
		call	divi
		ret
divi	proc	near
		mov		ax,	bx
		mov		dx,	0
		div		cx
		mov		bx,	dx
		mov		dl,	al
		add		dl,	30h
		mov		ah,	02h
		int		21h
		ret
divi	endp
funthi	endp

demo	proc	near
		mov		dl,	0ah
		mov		ah,	02h
		int		21h
		mov		dl,	0dh
		mov		ah,	02h
		int		21h
		ret
demo	endp
end		start
ends	code