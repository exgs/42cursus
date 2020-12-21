	global	_ft_write
	extern ___error
	section .text
_ft_write:
	mov		rax, 0x02000004 ; 		system call for write
	syscall ;		invoke operating system to do the write
	jc		error
	ret
	
error:
	mov		rdi, rax
	;push	rax
	;mov	rax, 0
	call	 ___error
	mov		[rax], rdi
	;pop		rax
	mov		rax, -1
	ret
	;push rax
	;call ___error
	;mov rdi, rax
	;pop rax
	;mov [rdi], rax
	;mov rax, -1
	;ret
