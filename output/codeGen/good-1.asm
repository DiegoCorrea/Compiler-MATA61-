.globl __start
.data 
.text
_func_main:
  move $fp, $sp
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
