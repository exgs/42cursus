	global	_ft_strlen
	section .text
_ft_strlen:
	mov		rax, 0
	jmp		loop
loop:
	cmp		byte [rdi + rax], 0
	je		done
	inc		rax
	jmp		loop
done:
	ret

