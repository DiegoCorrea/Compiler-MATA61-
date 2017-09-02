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
_func_somando:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
_func_pulando:
  move $fp, $sp
  sw $ra, 0($sp)
  addiu $sp, $sp, -4
_func_andando:
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
