module ControlUnit(
        /* Outputs */
        IorD, MemRead, MemWrite, MemToReg, IRWrite, RegDst, 
        RegWrite, ALUSrcA, ALUSrcB, ALUOp, PCSource, PCWrite, PCWriteCond,
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

    /* tmp */
    reg IorD_tmp, MemRead_tmp, MemWrite_tmp, MemToReg_tmp, IRWrite_tmp;
    reg RegDst_tmp, RegWrite_tmp, ALUSrcA_tmp, PCWrite_tmp, PCWriteCond_tmp;
    reg [1:0] ALUSrcB_tmp, ALUOp_tmp, PCSource_tmp;

    assign IorD = IorD_tmp;
    assign MemRead = MemRead_tmp;
    assign MemWrite = MemWrite_tmp;
    assign MemToReg = MemToReg_tmp;
    assign IRWrite = IRWrite_tmp;
    assign RegDst = RegDst_tmp;
    assign RegWrite = RegWrite_tmp;
    assign ALUSrcA = ALUSrcA_tmp;
    assign ALUSrcB = ALUSrcB_tmp;
    assign PCWrite = PCWrite_tmp;
    assign PCWriteCond = PCWriteCond_tmp;
    assign ALUOp = ALUOp_tmp;
    assign PCSource = PCSource_tmp;

    /* Initial state: Fetch */
	initial begin
        IorD_tmp = 0;
        MemRead_tmp = 1;
        MemWrite_tmp = 0;
        MemToReg_tmp = 0;
        IRWrite_tmp = 1;
        RegDst_tmp = 0;
        RegWrite_tmp = 0;
        ALUSrcA_tmp = 0;
        ALUSrcB_tmp = 01;
        PCWrite_tmp = 1;
        PCWriteCond_tmp = 0;
        ALUOp_tmp = 00;
        PCSource_tmp = 00;
	end

	always @(*) begin
        if(Clk == 1) begin
        /* Returns to initial state: Fetch */
        if (reset == 1) begin
            IorD_tmp = 0;
            MemRead_tmp = 1;
            MemWrite_tmp = 0;
            MemToReg_tmp = 0;
            IRWrite_tmp = 1;
            RegDst_tmp = 0;
            RegWrite_tmp = 0;
            ALUSrcA_tmp = 0;
            ALUSrcB_tmp = 01;
            PCWrite_tmp = 1;
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 00;
            PCSource_tmp = 00;
        end

        /* Verify instruction type */
        // Instrução SW  (opcode = 0x2B)
        if (Opcode == 6'h2B) begin
            IorD_tmp = 1; //
            MemRead_tmp = 0;
            MemWrite_tmp = 1; //
            MemToReg_tmp = 0;
            IRWrite_tmp = 0;
            RegDst_tmp = 0;
            RegWrite_tmp = 0;
            ALUSrcA_tmp = 1; //
            ALUSrcB_tmp = 2'b10; //
            PCWrite_tmp = 0;
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 00; //
            PCSource_tmp = 00;
        end
        // Instrução LW (opcode = 0x23)
        if (Opcode == 6'h23) begin
            IorD_tmp = 1; //
            MemRead_tmp = 1; //
            MemWrite_tmp = 0;
            MemToReg_tmp = 0;
            IRWrite_tmp = 0;
            RegDst_tmp = 0;
            RegWrite_tmp = 0;
            ALUSrcA_tmp = 1; //
            ALUSrcB_tmp = 2'b10; //
            PCWrite_tmp = 0;
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 00; //
            PCSource_tmp = 00;
        end
        // Instrução J (opcode = 0x02)
        if (Opcode == 6'h02) begin
            IorD_tmp = 0;
            MemRead_tmp = 0;
            MemWrite_tmp = 0;
            MemToReg_tmp = 0;
            IRWrite_tmp = 0;
            RegDst_tmp = 0;
            RegWrite_tmp = 0;
            ALUSrcA_tmp = 0;
            ALUSrcB_tmp = 0;
            PCWrite_tmp = 1; //
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 0;
            PCSource_tmp = 2'b10; //
        end
        // Instrução ADD (opcode = 0x00 e funct = 0x20)
        if (Opcode == 6'h00 && Funct == 6'h20) begin
            IorD_tmp = 0;
            MemRead_tmp = 0;
            MemWrite_tmp = 0;
            MemToReg_tmp = 0; //
            IRWrite_tmp = 0;
            RegDst_tmp = 1; //
            RegWrite_tmp = 1; //
            ALUSrcA_tmp = 1; //
            ALUSrcB_tmp = 00; //
            PCWrite_tmp = 0;
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 2'b10; //
            PCSource_tmp = 0;
        end
        // Instrução SUB (opcode = 0x00 e funct = 0x22)
        if (Opcode == 6'h00 && Funct == 6'h22) begin
            IorD_tmp = 0;
            MemRead_tmp = 0;
            MemWrite_tmp = 0;
            MemToReg_tmp = 0; //
            IRWrite_tmp = 0;
            RegDst_tmp = 1; //
            RegWrite_tmp = 1; //
            ALUSrcA_tmp = 1; //
            ALUSrcB_tmp = 00; //
            PCWrite_tmp = 0;
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 2'b10; //
            PCSource_tmp = 0;
        end
        // Instrução ADDI (opcode = 0x8)
        if (Opcode == 6'h08) begin
            IorD_tmp = 0;
            MemRead_tmp = 0;
            MemWrite_tmp = 0;
            MemToReg_tmp = 0; //
            IRWrite_tmp = 0;
            RegDst_tmp = 0; //
            RegWrite_tmp = 1; //
            ALUSrcA_tmp = 1; // 
            ALUSrcB_tmp = 2'b10; // 
            PCWrite_tmp = 0;
            PCWriteCond_tmp = 0;
            ALUOp_tmp = 00; //
            PCSource_tmp = 0;
        end
	end
    end
endmodule
