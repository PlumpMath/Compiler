.text

.globl Main
Main:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $4,%esp #make room for local variables
	pushl %ebx#Save Used Registor
	pushl $5
	popl %eax
	popl %ebx#save store register
	movl %ebp,%esp
	popl %ebp
	retl
