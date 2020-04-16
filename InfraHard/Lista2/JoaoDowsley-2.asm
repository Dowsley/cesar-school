.data
	str: .asciiz "Arrakis"
.text
	j main	# Start program
	strlen:
		li $v0, 0	# Start string count as zero
		loop:
			lb $t0, ($a0)		# Load char
			beqz $t0, endloop	# If char == \0 endloop; Else pass; 
			addi $v0, $v0, 1	# v0 += 1
			addi $a0, $a0, 1	# Point to the next char
			j loop				# Repeat procedure
		endloop:
			jr $ra
	main:
		la $a0, str
		jal strlen