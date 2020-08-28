        .model 	small
		.stack
		.data
arr		db	1h,5h,9h,43h,67h,23h,88h,41h,45h,82h,28h,61h,14h,40h
		.code
start:	mov		ax, @data
		mov		ds, ax
		nop
		mov		cx, 14-1
flagfi:	push	cx
		lea		si, arr
		mov		dl, 0
flagse:	lodsb
		mov		ah, [si]
		cmp		ah, al
		jnb		flagth
		mov		[si],   al
		mov		[si-1], ah
		mov		dl, 1
flagth:	loop	flagse
		pop		cx
		cmp		dl, 0
		jz		flagex
		loop	flagfi
flagex:	jmp		$
end		start
ends    code