.text
fact:
    beq 0, fact # if n > 0 -> return n * fact(n-1)
    
    endif:  # else i == 0 --> return 1
    
    jr $ra
main:
    # $a0 for input
    # $v1 for output (hi)
    # $v0 for output (lo)
    addi $a0, $zero, 3
    jal fact
