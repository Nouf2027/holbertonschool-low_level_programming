section .text
	  global main
main:
	    mov rax, 1
	    mov rdi, 1
	    mov rsi, message
	    mov rdx, message_end - message  ; NASM computes size
	    syscall

	    mov rax, 60
	    xor rdi, rdi
	    syscall
	  section .data
message:	 db "Hello, World", 0xA
message_end:
