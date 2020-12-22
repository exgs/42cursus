	global	_ft_strcpy
	section .text
_ft_strcpy:
	mov		rbx, 0
	cmp		rsi, 0
	je		done
	jmp		loop
loop:
	mov		dl, byte [rsi + rbx]
	mov		byte [rdi + rbx], dl
	cmp		byte [rsi + rbx], 0
	je		done
	inc		rbx
	jne		loop
done :
	mov		rax, rdi
	ret

