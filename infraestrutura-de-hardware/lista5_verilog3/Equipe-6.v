module decoder(Instruction, OpCode, Rs, Rt, Rd,
				shamt, funct, immediate, target);
	/* Inputs and outputs */
	input [31:0] Instruction;
	output [5:0] OpCode;
	output [4:0] Rs;
	output [4:0] Rt;
	output [4:0] Rd;
	output [4:0] shamt;
	output [5:0] funct;
	output [15:0] immediate;
	output [25:0] target;

	always @(*) begin
		OpCode <= Instruction[31:26];
		/* R-type */
		if (OpCode == 6'b0) begin
			Rs <= Instruction[25:21];
			Rt <= Instruction[20:16];
			Rd <= Instruction[15:11];
			shamt <= Instruction[10:6];
			funct <= Instruction[5:0];
			immediate <= 16'b0;
			target <= 26'b0;
		end
		/* J-type (2, 3 and 26) */
		if (OpCode == 6'b10 || OpCode == 6'b11 || OpCode == 6'b11010 ) begin
			Rs <= 5'b0;
			Rt <= 5'b0;
			Rd <= 5'b0;
			shamt <= 5'b0;
			funct <= 6'b0;
			immediate <= 16'b0;
			target <= Instruction[25:0];
		end
		/* I-type */
		else begin
			Rs <= Instruction[25:21];
			Rt <= Instruction[20:16];
			Rd <= 5'b0;
			shamt <= 5'b0;
			funct <= 6'b0;
			immediate <= Instruction[15:0];
			target <= 26'b0;
		end
	end
endmodule