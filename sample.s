.text

.globl Main
aain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $4,%esp #make room for local variables
	pushl $1
	popl %eax
	popl %ebp
	ret
Main:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $4,%esp #make room for local variables
	pushl $1
	popl %ebx
	movl %ebx,0(%esp)
	popl %eax
	popl %ebp
	ret
