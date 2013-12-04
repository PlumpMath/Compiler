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
	subl $56,%esp #make room for local variables
	pushl %ebx#Save Used Registor
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	pushl $0
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label0
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label0:#end if
	pushl $1
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label1
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label1:#end if
	pushl $1
	pushl $2
	popl %ebx
	popl %eax
	cmpl %ebx,%eax
	sete %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label2
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label2:#end if
	pushl $1
	pushl $2
	popl %ebx
	popl %eax
	cmpl %ebx,%eax
	setg %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label3
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label3:#end if
	pushl $1
	pushl $2
	popl %ebx
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label4
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label4:#end if
	pushl $2
	pushl $2
	popl %ebx
	popl %eax
	cmpl %ebx,%eax
	setl %al
	movzbl %al,%eax
	pushl %eax
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label5
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label5:#end if
	pushl $1
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label6
	pushl $1
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label6
	pushl $1
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label6
	pushl $1
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label6
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
	pushl $1
	popl %eax#start IfwithNoElse
	cmpl $1,%eax
	jne label6
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label6:#end if
label7:#end if
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label8:#end if
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label9:#end if
	pushl $0
	pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	pushl $0
pushl $4
	popl %ebx 
	popl %eax
	imull %ebx,%eax
	pushl %eax
	popl %eax 
	movl -4(%ebp, %eax, 4),%ebx
	pushl %ebx
	pushl $1
	popl %ebx 
	popl %eax
	addl %ebx,%eax
	pushl %eax
	popl %eax
	popl %ebx
	movl %eax,-4(%ebp, %ebx,4)
label10:#end if
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
	ret
