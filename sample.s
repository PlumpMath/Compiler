.text

.globl _Main
_ain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $4,%esp #make room for local variables
	pushl %ebx#Save Used Registor
	pushl $1
	pushl $2
	popl %ebx
	popl %eax
	cmpl %ebx,%eax
	setg %al
	movzbl %al,%eax
	pushl %eax
	popl %eax
	popl %ebx#save store register
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
	pushl %ebx#Save Used Registor
	pushl $1
	popl %ebx
	movl %ebx,-12(%ebp)
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
	popl %ebx#save store register
	movl %ebp,%esp
	popl %ebp
	ret
_Main:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $48,%esp #make room for local variables
	pushl %ebx#Save Used Registor
	pushl $2
	pushl $1
	popl %ebx#start visit call
	pushl %ebx
	popl %ebx#start visit call
	pushl %ebx
	call _aain
	popl %ebx
	popl %ebx
	push %eax
	pushl $10
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %ebx,-4(%ebp, %eax,4)
	pushl $10
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	popl %eax
	popl %ebx#save store register
	movl %ebp,%esp
	popl %ebp
	ret
