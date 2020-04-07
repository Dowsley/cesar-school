.text
    # RESULT MUST BE s0 = 0x123468FF;

    lui $s0, 0x1234
    ori $s0, $s0, 0x68FF
    
    # Step to step:
    
    # $s0 -> 0x00000000
    # lui -> 0x12340000
    # ori -> 0x12340000
    #        0x000068FF
    #        ----------  OR OPERATION
    #        0x123468FF