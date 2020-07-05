module ControlUnit(
        /* Outputs */
        IorD, MemRead, MemWrite, MemToReg, IRWrite, RegDst, 
        RegWrite, ALUSrcA, ALUSrcB, ALUOp, PCSource, PCWrite, PCWriteCond
        /* Inputs */
        Clk, reset, Opcode, Funct
    );

    /* Outputs */
    output IorD, MemRead, MemWrite, MemToReg, IRWrite;
    output RegDst, RegWrite, ALUSrcA, PCWrite, PCWriteCond;
    output [1:0] ALUSrcB, ALUOp, PCSource;

    /* Inputs */
    input Clk, reset;
    input [5:0] Opcode, Funct;

    /* Initial state: Fetch */
	initial begin
        IorD <= 0;
        MemRead <= 1;
        MemWrite <= 0;
        MemToReg <= 0;
        IRWrite <= 1;
        RegDst <= 0;
        RegWrite <= 0;
        ALUSrcA <= 0;
        ALUSrcB <= 01;
        PCWrite <= 1;
        PCWriteCond <= 0;
        ALUOp <= 00;
        PCSource <= 00;
	end

	always @(*) begin
        /* Returns to initial state: Fetch */
        if (reset == 1) begin
            IorD <= 0;
            MemRead <= 1;
            MemWrite <= 0;
            MemToReg <= 0;
            IRWrite <= 1;
            RegDst <= 0;
            RegWrite <= 0;
            ALUSrcA <= 0;
            ALUSrcB <= 01;
            PCWrite <= 1;
            PCWriteCond <= 0;
            ALUOp <= 00;
            PCSource <= 00;
        end

        /* Verify instruction type */
        // Instrução SW  (opcode = 0x2B)
        if (Opcode == 2'h2B) begin
            IorD <= 1; //
            MemRead <= 0;
            MemWrite <= 1; //
            MemToReg <= 0;
            IRWrite <= 0;
            RegDst <= 0;
            RegWrite <= 0;
            ALUSrcA <= 1; //
            ALUSrcB <= 2'b10; //
            PCWrite <= 0;
            PCWriteCond <= 0;
            ALUOp <= 00; //
            PCSource <= 00;
        // Instrução LW (opcode = 0x23)
        else if (Opcode == 2'h23) begin
            IorD <= 1; //
            MemRead <= 1; //
            MemWrite <= 0;
            MemToReg <= 0;
            IRWrite <= 0;
            RegDst <= 0;
            RegWrite <= 0;
            ALUSrcA <= 1; //
            ALUSrcB <= 2'b10; //
            PCWrite <= 0;
            PCWriteCond <= 0;
            ALUOp <= 00; //
            PCSource <= 00;
        // Instrução J (opcode = 0x02)
        else if (Opcode == 2'h02) begin
            IorD <= 0;
            MemRead <= 0;
            MemWrite <= 0;
            MemToReg <= 0;
            IRWrite <= 0;
            RegDst <= 0;
            RegWrite <= 0;
            ALUSrcA <= 0;
            ALUSrcB <= 0;
            PCWrite <= 1; //
            PCWriteCond <= 0;
            ALUOp <= 0;
            PCSource <= 2'b10; //
        // Instrução ADD (opcode = 0x00 e funct = 0x20)
        else if (Opcode == 2'h00 && Funct == 2'h20) begin
            IorD <= 0;
            MemRead <= 0;
            MemWrite <= 0;
            MemToReg <= 0; //
            IRWrite <= 0;
            RegDst <= 1; //
            RegWrite <= 1; //
            ALUSrcA <= 1; //
            ALUSrcB <= 00; //
            PCWrite <= 0;
            PCWriteCond <= 0;
            ALUOp <= 2'b10; //
            PCSource <= 0;
        // Instrução SUB (opcode = 0x00 e funct = 0x22)
        else if (Opcode == 2'h00 && Funct == 2'h22) begin
            IorD <= 0;
            MemRead <= 0;
            MemWrite <= 0;
            MemToReg <= 0; //
            IRWrite <= 0;
            RegDst <= 1; //
            RegWrite <= 1; //
            ALUSrcA <= 1; //
            ALUSrcB <= 00; //
            PCWrite <= 0;
            PCWriteCond <= 0;
            ALUOp <= 2'b10; //
            PCSource <= 0;
        // Instrução ADDI (opcode = 0x8)
        else if (Opcode == 2'h08) begin
            IorD <= 0;
            MemRead <= 0;
            MemWrite <= 0;
            MemToReg <= 0; //
            IRWrite <= 0;
            RegDst <= 0; //
            RegWrite <= 1; //
            ALUSrcA <= 1; // 
            ALUSrcB <= 2'b10; // 
            PCWrite <= 0;
            PCWriteCond <= 0;
            ALUOp <= 00; //
            PCSource <= 0;
        end
	end
endmodule