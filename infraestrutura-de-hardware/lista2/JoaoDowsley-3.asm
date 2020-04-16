.text
j main
fact:
	# Allocate space in the stack
	addi $sp, $sp, -8	# Allocates 2 units
	sw $ra, 0($sp)		# Stores func state into stack
	sw $s0, 4($sp)		# Store argument into stack
    
    # Base case (n == 0 --> return 1)
    li $v0, 1
    li $v1, 1
    beq $a0, 0, endfact	

    # n > 0 -> fact(n-1)
	move $s0, $a0
	addi $a0, $a0, -1
    jal fact
	
	# Multiplication
	mult $v0, $s0		# Multiply LO with return
	mflo $v0			# Get LO value
	mfhi $t0			# Get HI value
	mul $v1, $v1, $t0	# Multiply HI with return, goes to v1

	# Recover state data, and end stack session	
	endfact:
    	lw $s0, 4($sp)
    	lw $ra, 0($sp)
    	addi $sp, $sp, 8
    	jr $ra

main:
    # $a0 for input
    # $v1 for hi result
    # $v0 for lo result
    # $t0 for temp
    li $a0, 5
    move $t2, $a0
    jal fact
	move $a0, $t2