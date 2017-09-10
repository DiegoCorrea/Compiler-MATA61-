.data 
.text

main:
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
  li $a0, 4 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 5 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 1 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 2 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  jal _func_declara
  addiu $sp, $sp, 8 		#POP Arg List
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
  jal _func_print
  addiu $sp, $sp, 4 		#POP Arg List
  li $a0, 1 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  li $a0, 2 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw	$a0, 4($sp) 			#codeGen [SUM]
  lw	$t0, 8($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, 8 			#codeGen [SUM]
  add 	$a0, $t0, $a0 			#codeGen [SUM]
  sw	$a0, 0($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, -4 			#codeGen [SUM]
  li $a0, 10 			#codeGenExpr [DEC]
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
  jal _func_declara
  addiu $sp, $sp, 8 		#POP Arg List
  move $sp, $fp 		#POP Function
  lw $ra, 0($sp) 		#POP Function
  addiu $sp, $sp, 4 		#POP Function
  lw $fp, 0($sp) 		#POP Function
  jr $ra 		#POP Function

_func_declara: 		#Create Label
  sw $fp, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  lw $a0, 4($fp) 		#Load Parameters
  sw $a0, 0($sp) 		#Load Parameters
  addiu $sp, $sp, -4 		#Load Parameters
  lw $a0, 8($fp) 		#Load Parameters
  sw $a0, 0($sp) 		#Load Parameters
  addiu $sp, $sp, -4 		#Load Parameters
  sw $ra, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  addiu $sp, $sp, -4 		#Function Variable declaration
  lw $a0, 8($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  lw $a0, 4($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  lw	$a0, 4($sp) 			#codeGen [SUM]
  lw	$t0, 8($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, 8 			#codeGen [SUM]
  add 	$a0, $t0, $a0 			#codeGen [SUM]
  sw	$a0, 0($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, -4 			#codeGen [SUM]
  jal _func_print
  addiu $sp, $sp, 4 		#POP Arg List
  lw $a0, 8($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  lw $a0, 4($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  li $a0, 10 			#codeGenExpr [DEC]
  sw $a0, 0($sp) 		#codeGenExpr [DEC]
  addiu	$sp, $sp, -4 		#codeGenExpr [DEC]
  lw	$a0, 4($sp) 			#codeGen [MUL]
  lw	$t0, 8($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, 8 			#codeGen [MUL]
  mul 	$a0, $t0, $a0 			#codeGen [MUL]
  sw	$a0, 0($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, -4 			#codeGen [MUL]
  lw	$a0, 4($sp) 			#codeGen [SUM]
  lw	$t0, 8($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, 8 			#codeGen [SUM]
  add 	$a0, $t0, $a0 			#codeGen [SUM]
  sw	$a0, 0($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, -4 			#codeGen [SUM]
  sw $a0, -4($fp) 			#Assign
  addiu	$sp, $sp, 4 		#Assign
  lw $a0, -4($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  jal _func_print
  addiu $sp, $sp, 4 		#POP Arg List
  move $sp, $fp 		#POP Function
  lw $ra, 0($sp) 		#POP Function
  addiu $sp, $sp, 12 		#POP Function
  lw $fp, 0($sp) 		#POP Function
  jr $ra 		#POP Function

_func_o: 		#Create Label
  sw $fp, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  sw $ra, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  move $sp, $fp 		#POP Function
  lw $ra, 0($sp) 		#POP Function
  addiu $sp, $sp, 4 		#POP Function
  lw $fp, 0($sp) 		#POP Function
  jr $ra 		#POP Function

_func_maisuma: 		#Create Label
  sw $fp, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  lw $a0, 4($fp) 		#Load Parameters
  sw $a0, 0($sp) 		#Load Parameters
  addiu $sp, $sp, -4 		#Load Parameters
  lw $a0, 8($fp) 		#Load Parameters
  sw $a0, 0($sp) 		#Load Parameters
  addiu $sp, $sp, -4 		#Load Parameters
  lw $a0, 12($fp) 		#Load Parameters
  sw $a0, 0($sp) 		#Load Parameters
  addiu $sp, $sp, -4 		#Load Parameters
  sw $ra, 0($sp) 		#Activation Record
  move $fp, $sp 		#Activation Record
  addiu $sp, $sp, -4 		#Activation Record
  lw $a0, 8($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  lw $a0, 4($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  lw $a0, 12($fp) 			#codeGenExpr [ID]
  sw $a0, 0($sp) 		#codeGenExpr [ID]
  addiu	$sp, $sp, -4 		#codeGenExpr [ID]
  lw	$a0, 4($sp) 			#codeGen [MUL]
  lw	$t0, 8($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, 8 			#codeGen [MUL]
  mul 	$a0, $t0, $a0 			#codeGen [MUL]
  sw	$a0, 0($sp) 			#codeGen [MUL]
  addiu	$sp, $sp, -4 			#codeGen [MUL]
  lw	$a0, 4($sp) 			#codeGen [SUM]
  lw	$t0, 8($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, 8 			#codeGen [SUM]
  add 	$a0, $t0, $a0 			#codeGen [SUM]
  sw	$a0, 0($sp) 			#codeGen [SUM]
  addiu	$sp, $sp, -4 			#codeGen [SUM]
  move $sp, $fp 		#POP Function
  lw $ra, 0($sp) 		#POP Function
  addiu $sp, $sp, 16 		#POP Function
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
