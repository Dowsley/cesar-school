module decode_tb;
	reg [31:0] Instruction;
	wire [5:0] OpCode;
	wire [4:0] Rs;
	wire [4:0] Rt;
	wire [4:0] Rd;
	wire [4:0] shamt;
	wire [5:0] funct;
	wire [15:0] immediate;
	wire [25:0] target;

	initial begin
        /* R-type */
        Instruction = 32'b00000000001000100001100100000101;
        /* RETORNO CORRETO:
        OpCode = 0 
        Rs = 1 
        Rt = 2
        Rd = 3
        Shamt = 4
        funct = 5 
        immediate = 0
        target = 0 */
        #1
        /* I-type */
        Instruction = 32'b10001100001000100000000000000011;
        /* RETORNO CORRETO: 
        Opcode = 35 (lw)
        rs = 1
        rt = 2
        rd = 0
        shamt = 0
        funct = 0
        immediate = 3 
        target = 0 */
        #1
        /* J-type */
        Instruction = 32'b00001000000000000000000000000011;
        /* RETORNO CORRETO:
        Opcode = 2 (j) 
        target = 3 */ 
    end

	decoder op (Instruction,OpCode,Rs,Rt,Rd,shamt,funct,immediate,target);
endmodule 
