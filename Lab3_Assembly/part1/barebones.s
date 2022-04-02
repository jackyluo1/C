# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans:
	pushq %rbp			# Save parent to rbp
	movq  %rsp, %rbp		# Move rsp to rbp

					# (2) What is going on here
					# Ans:
	movq $1, %rax			# mov 1 to register rax
	movq $1, %rdi			# mov 1 to register rdi
<<<<<<< HEAD
	leaq .hello.str,%rsi		# leaq hello.str to ris
=======
	leaq .hello.str,%rsi		# lead hello.str to ris
>>>>>>> 330b19003dbddc56f1d8a8c5bde92cf675ee45b9


					# (3) What is syscall? We did not talk about this
					# in class.
<<<<<<< HEAD
					# Ans:syscall is a small library function that invokes the system call whose assembly language interface has the specified number with the specified arguments.

	syscall				# Which syscall is being run?
					# Ans:leaq .hello.str,%rsi

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans:AUDITSYSCALL

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	mov 1 to register rdi

=======
					# Ans: syscall is a small library function that invokes the system call whose assembly language interface has the specified number with the specified arguments.
	syscall				# Which syscall is being run?
					# Ans: leaq .hello.str,%rsi

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans:AUDITSYSCALL？

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: mov 1 to register rdi
>>>>>>> 330b19003dbddc56f1d8a8c5bde92cf675ee45b9
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:the size is 13.	
