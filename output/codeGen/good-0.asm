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
_func_somando:
_func_pulando:
_func_andando:

__start:
  sw $fp, 0($sp)
  jal _func_main
  li $v0, 10
  syscall
