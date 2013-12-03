.text

.globl _Main
_aain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $12,%esp #make room for local variables
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
	popl %eax
	movl %ebp,%esp
	popl %ebp
	ret
_Main:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $8,%esp #make room for local variables
	pushl $2
	popl %ebx#start visit call
	pushl %ebx
	call _aain
	movl %eax,-8(%ebp)#end visit call
	popl %ebx
	popl %ebx
	movl -8(%ebp),%ebx
	pushl %ebx
	popl %eax
	movl %ebp,%esp
	popl %ebp
	ret
