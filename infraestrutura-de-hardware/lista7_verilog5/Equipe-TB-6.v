module Control_TB;

    /* Outputs */
    wire IorD, MemRead, MemWrite, MemToReg, IRWrite;
    wire RegDst, RegWrite, ALUSrcA, PCWrite, PCWriteCond;
    wire [1:0] ALUSrcB, ALUOp, PCSource;

    /* Inputs */
    reg Clk, reset;
    reg [5:0] Opcode, Funct;

    initial
        begin
            Clk = 1;
            reset = 1;
            Funct = 0;
        end

    always begin
       #10
       Clk = ~Clk;
    end


    always begin
        #20
        reset = 0;
        Opcode <= 6'h2B;
        #20
        Opcode <= 6'h23;
        #20
        Opcode <= 6'h02;
        #20
        Opcode <= 6'h00;
        Funct <= 6'h20;
        #20
        Opcode <= 6'h00;
        Funct <= 6'h22;
        #20
        Opcode <= 6'h08;
    end
    
    ControlUnit Op (IorD, MemRead, MemWrite, MemToReg, IRWrite, RegDst, 
    RegWrite, ALUSrcA, ALUSrcB, ALUOp, PCSource, PCWrite, PCWriteCond, Clk, reset, Opcode, Funct);

endmodule