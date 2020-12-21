	global	ft_write

	section .text
ft_write:
	mov		rax, 0x02000004 ; 		system call for write
	mov		rdi, 1 ;				file handle 1 is stdout
	mov		rsi, message ;			address of string to output
	mov		rdx, 5 ;
	syscall ;		invoke operating system to do the write
	mov		rax, 0x02000001	; 	system call for exit
	xor		rdi, rdi ; initialize
	syscall

	section .data
message:
	db		"Hello, world",10 ; note the newline at the end
