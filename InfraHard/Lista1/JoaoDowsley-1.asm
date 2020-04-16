# NT: Sum of all elements must be 24D

.data
    array: .word 0x10, 0x67, 0x90, 0x56, 0x45, 0x12, 0x99

# a0 = array head 
# a1 = array max memory address for size 7 (stop condition)
# t0 = temporary value holder 
# v0 = sum value holder. 
.text
    la $a0, array     # Loads address of array[0] to t0
    addi $a1, $a0, 28 # Max index for size 7 is addr + 24. 28 will serve as stop condition.
    li $v0, 0         # Initializing sum as 0
    loop:
        lw   $t0, 0($a0)         # Loads array element in any given position at t0 (temp).
        add  $v0, $v0, $t0    	 # $v0 += $t0 -> Increments sum.
        addi $a0, $a0, 4    	 # $a0 += 4 -> Moves index, or offset, +1 element.
        beq  $a0, $a1, exit_loop # if $a0 == $a1 then target [ HAS IT REACHED MAX MEMADDRESS? If yes, break.]
        j loop                   # Otherwise, proceed.
    exit_loop:
