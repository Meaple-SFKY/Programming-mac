        .model	small
        .stack
        .data
result	db		5 dup(?)
minu	dw		88h,44h,66h,00h,99h
numfir	=		$-minu
subtra	dw		22h,55h,88h
numsec	=		$-subtra
        .code
start:	mov		ax, @data
		mov		ds, ax
		mov		es, ax
		push	ds
		xor		ax, ax
		push	ax
		std
		call	funsec
		lea		si, minu
		add		si, numfir-1
		mov		cx, numfir
		call	funfir
		jmp		$
funfir	proc	near
		push	ax
		push	dx
flagfi:		lodsb
		lea		bx, result
		add		bx, cx
		mov		[bx],   al
		loop	flagfi
		pop		dx
		pop		ax
		ret
funfir	endp
funsec	proc	near
		lea		si, minu
		lea		di, subtra
		mov		bx, numfir
		mov		cx, numsec
		clc
flagse:	mov		al, [di]
		sbb		[si],   al
		inc		di
		inc		si
		dec		bx
		loop	flagse
flagth:	jz		flagfo
		jnc		flagfo
		sbb		byte ptr [si],  0
		inc		si
		dec		bx
		jmp		flagth
flagfo:	ret
funsec	endp
end		start
ends    code