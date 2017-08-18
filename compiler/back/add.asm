	.data
menSum: .asciiz "Soma: "
menSub: .asciiz "Subtracao: "
menMul: .asciiz "Multiplicacao: "
menDiv: .asciiz "Divisao: "
menSigChange: .asciiz "Trocando sinal: "


breakLine: .asciiz	"\n"
	.text
__start:
	#save return point
	sw	$ra, 0($sp)			# Salva o $ra no topo da pilha
	addiu	$sp,$sp,-4		# Aloca espaco na pilha para 1 palavra (4 bytes)
	#end save return point
	
	###################
	la	$a0,menSum
	li	$v0,4
	syscall
	jal	codeGenSum
  	li  	$v0, 1         		# specify Print Integer service
	syscall              		# print the prompt string
	la	$a0,breakLine
	li	$v0,4
	syscall
	##################
	la	$a0,menSub
	li	$v0,4
	syscall
	jal	codeGenSub
  	li  	$v0, 1         		# specify Print Integer service
	syscall              		# print the prompt string
	la	$a0,breakLine
	li	$v0,4
	syscall
	#################
	la	$a0,menMul
	li	$v0,4
	syscall
	jal	codeGenMul
  	li  	$v0, 1         		# specify Print Integer service
	syscall              		# print the prompt string
	la	$a0,breakLine
	li	$v0,4
	syscall
	#################
	la	$a0,menDiv
	li	$v0,4
	syscall
	jal	codeGenDiv
  	li  	$v0, 1         		# specify Print Integer service
	syscall              		# print the prompt string
	la	$a0,breakLine
	li	$v0,4
	syscall
	#################
	la	$a0, menSigChange
	li	$v0, 4
	syscall
	jal	codeGenSignalChange
  	li  	$v0, 1         		# specify Print Integer service
	syscall              		# print the prompt string
	la	$a0, breakLine
	li	$v0,4
	syscall
	#################
	li	$v0, 10			# system call for exit
	syscall

codeGenSum:
######## Push integers on Stack
	li	$a0, 10
	li	$t0, -2
	addi	$sp, $sp, -8

	sw	$a0, 0($sp)
	sw	$t0, 4($sp)
######## end

######## Pop intergers from Stack and push on registers
	lw	$a0, 0($sp)
	lw	$t0, 4($sp)
	addi	$sp, $sp, 8
######### end

######### Sum registers
	add 	$a0, $t0, $a0
######### end

######### Push result on Stack
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
######### end
	jr $ra
	
codeGenSub:
######## Push integers on Stack
	li	$a0, 10
	li	$t0, 2
	addi	$sp, $sp, -8

	sw	$a0, 0($sp)
	sw	$t0, 4($sp)
######## end

######## Pop intergers from Stack and push on registers
	lw	$a0, 0($sp)
	lw	$t0, 4($sp)
	addi	$sp, $sp, 8
######### end

######### Sub registers
	sub 	$a0, $t0, $a0
######### end

######### Push result on Stack
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
######### end
	jr $ra
	
codeGenMul:
######## Push integers on Stack
	li	$a0, 10
	li	$t0, 2
	addi	$sp, $sp, -8

	sw	$a0, 0($sp)
	sw	$t0, 4($sp)
######## end

######## Pop intergers from Stack and push on registers
	lw	$a0, 0($sp)
	lw	$t0, 4($sp)
	addi	$sp, $sp, 8
######### end

######### Multiplay registers
	mul 	$a0, $t0, $a0
	#mfhi	$a0		#  move quantity in special register Hi to $t0:   $a0 = Hi
######### end

######### Push result on Stack
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
######### end
	jr $ra
	
codeGenDiv:
######## Push integers on Stack
	li	$a0, 10
	li	$t0, 2
	addi	$sp, $sp, -8

	sw	$a0, 0($sp)
	sw	$t0, 4($sp)
######## end

######## Pop intergers from Stack and push on registers
	lw	$a0, 0($sp)
	lw	$t0, 4($sp)
	addi	$sp, $sp, 8
######### end

######### Sum registers
	div 	$t0, $a0
	mfhi	$a0 
######### end

######### Push result on Stack
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
######### end
	jr $ra
	
codeGenSignalChange:
######## Push integer on Stack
	li	$a0, -10
	li	$t0, -1
	addi	$sp, $sp, -4

	sw	$a0, 0($sp)
######## end

######## Pop intergers from Stack and push on registers
	lw	$a0, 0($sp)
	addi	$sp, $sp, 4
######### end

######### Sum registers
	mul 	$a0, $t0, $a0
######### end

######### Push result on Stack
	addi 	$sp, $sp, -4
	sw	$a0, 0($sp)
######### end
	jr $ra