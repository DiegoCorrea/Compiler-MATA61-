.globl __start
.data 
.text
_func_main:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
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
_func_outra:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
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
_func_print:
  li $v0, 1
  syscall
  j $ra

__start:
  sw $fp, 0($sp)
  jal _func_main
  li $v0, 10
  syscall
