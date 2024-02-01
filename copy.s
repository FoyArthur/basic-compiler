.text
.globl main
.type main, @function

main:
	lea a(%rip), %eax
	mov $20, %ebx
	mov %ebx, (%eax)

	push %rbx
	lea format(%rip), %rdi
	mov a, %esi
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

