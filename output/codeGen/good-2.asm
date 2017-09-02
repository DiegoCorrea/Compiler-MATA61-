.globl __start
.data 
.text

_func_main:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  li $a0, 4 		#codeGenExpr
  sw $a0, 0($sp) 		#codeGenExpr
  addiu	$sp, $sp, -4 		#codeGenExpr
  jal _func_print
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_pilhala:
  move $fp, $sp
  sw 16($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 12($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 8($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 4($fp), 0($sp)
  addiu $sp, $sp, -4
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_outra:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_grandona:
  move $fp, $sp
  sw 28($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 24($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 20($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 16($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 12($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 8($fp), 0($sp)
  addiu $sp, $sp, -4
  sw 4($fp), 0($sp)
  addiu $sp, $sp, -4
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
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
