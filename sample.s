.text

.globl _Main
_ain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $4,%esp #make room for local variables
	popl %ebx
	popl %eax
	cmpl %ebx,%eax
	setg %al
	movzbl %al,%eax
	pushl %eax
	popl %eax
	movl %ebp,%esp
	popl %ebp
	ret
_aain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $16,%esp #make room for local variables
	movl 12(%ebp),%ebx
	movl %ebx,-4(%ebp)
	movl 8(%ebp),%ebx
	movl %ebx,-8(%ebp)
	movl -4(%ebp),%ebx
	pushl %ebx
	movl -8(%ebp),%ebx
	pushl %ebx
	popl %ebx
	popl %eax
	addl %ebx,%eax
	pushl %eax
	movl -12(%ebp),%ebx
	pushl %ebx
	popl %ebx
	popl %eax
	addl %ebx,%eax
	pushl %eax
	pushl $4
	popl %ebx
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	movl %ebp,%esp
	popl %ebp
	ret
_Main:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $8,%esp #make room for local variables
	popl %ebx
	popl %eax
	orl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-4(%ebp)
	pushl $0
	popl %eax
	movl %ebp,%esp
	popl %ebp
	ret
