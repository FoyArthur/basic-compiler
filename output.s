
.text
.globl main
.type main, @function

main:
	

// pushing 35 to stack
mov $35, %rax
push %rax


// pushing 7 to stack
mov $7, %rax
push %rax


// pushing 6 to stack
mov $6, %rax
push %rax


//imul
pop %rax
pop %rbx
imul %rax, %rbx
push %rbx


//add
pop %rax
pop %rbx
add %rax, %rbx
push %rbx


// pushing 3 to stack
mov $3, %rax
push %rax


//sub
pop %rax
pop %rbx
sub %rax, %rbx
push %rbx


// assigning x
pop %rbx
lea x(%rip), %rax
mov %rbx, (%rax)


//pushing x to stack
lea x(%rip), %rax
mov (%rax), %rbx
push %rbx


//Printing
pop %rbx
push %rax
lea format(%rip), %rdi
mov %rbx, %rsi
xor %eax, %eax
call printf@plt
pop %rax


//Assembly End
mov $60, %rax
xor %rdi, %rdi
syscall

.data

format:
	.asciz "%d\n"

x:
	.long 0
