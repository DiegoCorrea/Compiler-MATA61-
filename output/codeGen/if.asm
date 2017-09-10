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
