.text
.globl main
.type main, @function

main:
	push %rax
	lea format(%rip), %rdi
	lea a(%rip), %rbx
	movl (%rbx), %esi
	xor %eax, %eax
	call printf@plt
	pop %rbx

mov $60, %rax
xor %rdi, %rdi
syscall

.data

format:
	.asciz "%d\n"

a:
	.long 0

