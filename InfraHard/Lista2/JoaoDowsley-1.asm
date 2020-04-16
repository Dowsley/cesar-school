 .text
	j main	# Start program
	function:	# Output: $v0 (result) || Inputs: $a0 (operand 1), $a1 (operand 2), $a2 (operation id)
		beq $a2, 1, if_sum	# 1 == SUM
		beq $a2, 2, if_sub	# 2 == SUB
		beq $a2, 3, if_and	# 3 == AND
		beq $a2, 4, if_or	# 4 == OR
		if_sum:
			add $v0, $a0, $a1	# v0 = a0 + a1
			jr $ra
		if_sub:
			sub $v0, $a0, $a1	# v0 = a0 - a1
			jr $ra
		if_and:
			and $v0, $a0, $a1	# v0 = a0 and a1
			jr $ra
		if_or:
			or $v0, $a0, $a1	# v0 = a0 or a1
			jr $ra

	main:
		li $s5, 5	# 0b101
		li $s6, 2	# 0b10
		add $a0, $zero, $s5
		add $a1, $zero, $s6 
		
		li $a2, 1
		jal function	# Call 1 (Sum in $s0) [EXPECTED: s0 = 7]
		add $s0, $zero, $v0
		
		li $a2, 2
		jal function	# Call 2 (Sub in $s1) [EXPECTED: s1 = 3]
		add $s1, $zero, $v0

		li $a2, 3
		jal function	# Call 3 (AND in $s2) [EXPECTED: s2 = 0x0]
		add $s2, $zero, $v0

		li $a2, 4
		jal function	# Call 4 (OR in $s3) [EXPECTED: s3 = 0x7]
		add $s3, $zero, $v0