.text
	li $v0, 10	# v0 = Current number (starts as 10, stops at 40)
	li $v1, 0	# v1 = Total sum (starts as 0)
	loop:
		add $v1, $v1, $v0	# v1 (sum) += v0 (curr number)
		addi $v0, $v0, 1	# v0 += 1 (Increment current number)
		beq $v0, 41, end_loop	# if stop condition (v0 == 41) met, end loop.
		j loop
	end_loop: