	global	_ft_read
	extern ___error
	section .text
_ft_read:
	mov		rax, 0x02000003 ;		system call for read
	syscall                 ;		invoke operating system to do the read
	jc		error
	ret
	
error:
	mov		rdi, rax
	call	 ___error
	mov		[rax], rdi
	mov		rax, -1
	ret
	
	;push rax
	;call ___error
	;mov rdi, rax
	;pop rax
	;mov [rdi], rax
	;mov rax, -1
	;ret
