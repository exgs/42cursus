	global	_ft_strcmp
	section .text
_ft_strcmp:
	push	rbx
	push	r8
	mov		rbx, 0
	jmp		loop
loop:
	movzx	rcx, byte [rdi + rbx]
	movzx	rdx, byte [rsi + rbx]
	mov		r8,	rcx
	or		r8, rdx
	cmp		r8, 0
	je		return_same
	sub		rcx, rdx
	cmp		rcx, 0
	jne		return_value
	inc		rbx ; flag change(i don't know why)
	cmp		rcx, 0
	je		loop
return_same:
	pop		r8
	pop		rbx
	mov		rax, 0
	ret
return_value:
	mov		rax, rcx
	pop		r8
	pop		rbx
	ret
