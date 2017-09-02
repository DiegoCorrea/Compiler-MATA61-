.globl __start
.data 
.text

_func_main:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  li $a0, 2 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  li $a0, 1 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  lw	$a0, 4($sp)
  lw	$t0, 8($sp)
  addiu	$sp, $sp, 8
  add 	$a0, $t0, $a0
  addiu	$sp, $sp, -4
  sw	$a0, 0($sp)
  addiu	$sp, $sp, -4
  li $a0, 2 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  li $a0, 3 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  lw	$a0, 4($sp)
  lw	$t0, 8($sp)
  addiu	$sp, $sp, 8
  mul 	$a0, $t0, $a0
  addiu	$sp, $sp, -4
  sw	$a0, 0($sp)
  addiu	$sp, $sp, -4
  li $a0, 4 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  li $a0, 8 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  lw  $a0, 4($sp)
  lw  $t0, 8($sp)
  addiu	$sp, $sp, 8
  div	$t0, $a0
  mfhi	$a0
  addiu	$sp, $sp, -4
  sw	$a0, 0($sp)
  addiu	$sp, $sp, -4
  li $a0, 2 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  li $a0, 5 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  lw	$a0, 4($sp)
  lw	$t0, 8($sp)
  addiu	$sp, $sp, 8
  sub 	$a0, $t0, $a0
  addiu	$sp, $sp, -4
  sw	$a0, 0($sp)
  addiu	$sp, $sp, -4
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_declara:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  addiu $sp, $sp, -4 #codeGenFunctionBlockVariable
  li $a0, 5 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  li $a0, 10 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_print:
  lw	$a0, 4($sp)
  li $v0, 1
  syscall
  li $v0, 11
  li $a0, 0x0a
  syscall
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  addiu $sp, $sp, 4
  jr $ra

__start:
  sw $fp, 0($sp)
  jal _func_main
  li $v0, 10
  syscall
