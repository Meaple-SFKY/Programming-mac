        .model	small
		.stack
	    .data
		.code
start:	mov		ax, @data
		mov		ds, ax
		mov 	es, ax
		mov 	cx, 100h
		mov 	si, 3000h
		mov 	di, 6000h
		call	func
		mov 	cx, 100h
	    mov 	si, 3000h
	    mov 	di, 6000h
		cld
		repe	cmpsb
		jne		err
true:	jmp 	$
err:	jmp 	$
func	proc	near
		cld
		cmp 	si, di
		jz		return
		jnb		flag
	    add 	si, cx
		dec 	si
		add 	di, cx
		dec 	di
		std
flag:	rep		movsb
return:	ret
func	endp
end		start
ends    code