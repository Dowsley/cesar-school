.data
lista: .word 0x20, 0x30, 0x40, 0x50

.text
la $t0, lista
lw $s0, 0($t0)