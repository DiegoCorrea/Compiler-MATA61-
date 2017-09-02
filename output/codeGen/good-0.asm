.globl __start
.data 
  a: 	 .word 	 150152 
  b: 	 .word 
  c: 	 .word 
  d: 	 .word 
  e: 	 .word 	 8 
  f: 	 .word 	 0 
  g: 	 .word 	 5 
  essavariavelehgrandecomoaporra: 	 .word 	 9999999 
.text

_func_main:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_somando:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_pulando:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
  lw $ra, 4($sp)
  addiu $sp, $sp, 4
  lw $fp, 4($sp)
  jr $ra

_func_andando:
  move $fp, $sp
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
