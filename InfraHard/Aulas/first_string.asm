.data
    str1: .asciiz "abcde"

.text
    la $s0, str1
    lb $s0, 0($t0)  # $s0 = texto[0]
    lb $s0, 1($t0)  # $s0 = texto[1]
    lb $s0, 2($t0)  # $s0 = texto[2]
    sb $s0, 0($t0)  # texto[0] = $s0
    