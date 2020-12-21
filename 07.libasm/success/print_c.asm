	extern _c
	section .text
	global _print_c
_print_c:
	mov rax, 0x02000004
	mov rdi, 1
	lea rsi, [rel message]
	mov rdx, 2
	syscall
	
	mov rax, 0x02000004
	;mov rdi, 1
	lea rsi, [rel _c]
	;mov rdx, 6
	syscall
	mov		rax, 0x02000001
	xor		rdi, rdi
	syscall

	section .data
message:
	db		"hello, world",10
