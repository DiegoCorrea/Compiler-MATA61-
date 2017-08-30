.globl __start
.data 
  a: 	 .word 	 0 
  b: 	 .word 
  c: 	 .word 
  d: 	 .word 
  e: 	 .word 	 0 
  f: 	 .word 	 0 
  g: 	 .word 	 0 
  essavariavelehgrandecomoaporra: 	 .word 	 0 
.text

__start:
  sw $fp, 0($sp)
  li $v0, 10
  syscall
