# NT: Below 91 are LowerCase. Above 91 is UpperCase.
# s1 = First String Memory Address
# s2 = Second String Memory Address

# t0 = Temporary character holder

# v0 = Temporary verifier for the IF statement.
# v1 = String size in bytes.

.data
	str1: .asciiz "WeLcOmE"
	str2: .asciiz ""
.text
	la $s1, str1
	la $s2, str2
	Run:
		lb $t0, ($s1)		# Load char
		beqz $t0, End		# If char == TERMINATOR, End Program
		addi $v1, $v1, 1	# Increment string size +1 byte 
		# - Lowercase Verification -
		slti $v0, $t0, 91	# 1 If UpperCase. 0 if LowerCase.
		beq $v0, 1, Endif	# Skips to normal procedure if UpperCase.
		# - Lowercase parsing. - (subtract 32 for Upper conversion)
		subi $t0, $t0, 32	# t0 -= 32
	Endif:
		sb $t0, ($s2)		# Store into the array position
		addi $s1, $s1, 1	# Move to the next byte (str1)
		addi $s2, $s2, 1	# Move to the next byte (str2)
		j Run			# Restarts the loop
	End:
		sb $t0, ($s2) # Store the NULL Terminator into the second string.
