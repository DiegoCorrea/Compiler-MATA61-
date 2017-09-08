.globl __start
.data 
.text

__start:
  move $fp, $sp 		#Start Mips
  addiu $sp, $sp, -4 		#Start Mips
  jal _func_main 		#Start Mips
  li $v0, 10 		#Start Mips
  syscall 		#Start Mips

_func_main: 		#Create Label
  sw $fp, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  sw $ra, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  li $a0, 2 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 2 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw	$a0, 4($sp) 			#codeGen [MUL]
  lw	$t0, 8($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, 8 			#codeGen [MUL]
  mul 	$a0, $t0, $a0 			#codeGen [MUL]
  sw	$a0, 0($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, -4 			#codeGen [MUL]
  li $a0, 1 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw	$a0, 4($sp) 			#codeGen [SUM]
  lw	$t0, 8($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, 8 			#codeGen [SUM]
  add 	$a0, $t0, $a0 			#codeGen [SUM]
  sw	$a0, 0($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, -4 			#codeGen [SUM]
  li $a0, 2 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 3 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw	$a0, 4($sp) 			#codeGen [MUL]
  lw	$t0, 8($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, 8 			#codeGen [MUL]
  mul 	$a0, $t0, $a0 			#codeGen [MUL]
  sw	$a0, 0($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, -4 			#codeGen [MUL]
  li $a0, 4 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 8 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw  $a0, 4($sp) 			#codeGen [DIV]
  lw  $t0, 8($sp) 			#codeGen [DIV]
  addiu	$sp, $sp, 8 			#codeGen [DIV]
  div	$t0, $a0 			#codeGen [DIV]
  mfhi	$a0 			#codeGen [DIV]
  sw	$a0, 0($sp) 			#codeGen [DIV]
  addiu	$sp, $sp, -4 			#codeGen [DIV]
  li $a0, 2 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 5 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw	$a0, 4($sp) 			#codeGen [SUB]
  lw	$t0, 8($sp) 			#codeGen [SUB]
  addiu	$sp, $sp, 8 			#codeGen [SUB]
  sub 	$a0, $t0, $a0 			#codeGen [SUB]
  sw	$a0, 0($sp) 			#codeGen [SUB]
  addiu	$sp, $sp, -4 			#codeGen [SUB]
  jal _func_declara
  addiu $sp, $sp, 0 		#POP Arg List
  move $sp, $fp 		#POP Function
  lw $ra, 0($sp) 		#POP Function
  addiu $sp, $sp, 4 		#POP Function
  lw $fp, 0($sp) 		#POP Function
  jr $ra 		#POP Function

_func_declara: 		#Create Label
  sw $fp, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  sw $ra, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  addiu $sp, $sp, -4 		#codeGenFunctionBlockVariable
  li $a0, 5 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 10 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  move $sp, $fp 		#POP Function
  lw $ra, 0($sp) 		#POP Function
  addiu $sp, $sp, 4 		#POP Function
  lw $fp, 0($sp) 		#POP Function
  jr $ra 		#POP Function

_func_print:
  lw	$a0, 4($sp)
  li $v0, 1
  syscall
  li $v0, 11
  li $a0, 0x0a
  syscall
  jr $ra
