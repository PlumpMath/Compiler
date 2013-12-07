.text

.globl Main
ain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $4,%esp #make room for local variables
	pushl %ebx#Save Used Registor
	pushl $0#OPT:0
	popl %eax
	popl %ebx#save store register
	movl %ebp,%esp
	popl %ebp
	retl
aain:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $16,%esp #make room for local variables
	movl 8(%ebp),%ebx
	movl %ebx,-4(%ebp)
	movl 12(%ebp),%ebx
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
	retl
Main:
	pushl %ebp #Save Original EBP
	movl %esp,%ebp #Point EBP to top of stack
	subl $56,%esp #make room for local variables
	pushl %ebx#Save Used Registor
	pushl $2
	pushl $1
	popl %ebx#start visit call
	pushl %ebx
	popl %ebx#start visit call
	pushl %ebx
	call aain
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
	pushl $0
	popl %ebx
	movl %ebx,-52(%ebp)
label0:#top
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $10
	popl %ebx#Starting:setl
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label1
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	movl -52(%ebp),%ebx
	pushl %ebx
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-52(%ebp)
	jmp label0
label1:#end if
	pushl $0
	popl %ebx
	movl %ebx,-52(%ebp)
label2:#top
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $10
	popl %ebx#Starting:setl
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label3
	pushl $1
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	movl -52(%ebp),%ebx
	pushl %ebx
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-52(%ebp)
	jmp label2
label3:#end if
	pushl $0
	popl %ebx
	movl %ebx,-48(%ebp)
	pushl $0
	popl %ebx
	movl %ebx,-44(%ebp)
label4:#top
	movl -44(%ebp),%ebx
	pushl %ebx
	pushl $10
	popl %ebx#Starting:setl
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label5
	pushl $0
	popl %ebx
	movl %ebx,-52(%ebp)
label6:#top
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $10
	popl %ebx#Starting:setl
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label7
	movl -48(%ebp),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-48(%ebp)
	pushl $3
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	movl -48(%ebp),%ebx
	pushl %ebx
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-52(%ebp)
	jmp label6
label7:#end if
	movl -44(%ebp),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-44(%ebp)
	jmp label4
label5:#end if
	pushl $0
	popl %ebx
	movl %ebx,-52(%ebp)
label8:#top
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $10
	popl %ebx#Starting:setl
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label9
	movl -52(%ebp),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %ebx
	movl %ebx,-52(%ebp)
	pushl $2
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	movl -52(%ebp),%ebx
	pushl %ebx
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	jmp label8
label9:#end if
	pushl $4
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $3
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	pushl $0
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
	retl
