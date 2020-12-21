		global	_ft_puts
		extern	_puts

		section	.text
_ft_puts:	
		push	rbx
		;lea		rdi, [rel message]
		call	_puts
		pop		rbx
		ret

		section .data
message:	db		"hola, mundo", 0
