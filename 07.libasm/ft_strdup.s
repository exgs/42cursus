	global	_ft_strdup
	extern	_ft_strlen
	extern	_malloc
	extern	_ft_strcpy
	section .text
_ft_strdup:
	cmp		rdi, 0
	je		return_null
	call	_ft_strlen
	push	rdi
	mov		rdi, rax
	inc		rdi
	call	_malloc
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret
return_null:
	push	rdi
	mov		rdi, 1
	call	_malloc
	pop		rdi
	ret
