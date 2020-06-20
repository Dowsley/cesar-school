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

	reg [5:0] OpCodeOut;
	reg [4:0] RsOut;
	reg [4:0] RtOut;
	reg [4:0] RdOut;
	reg [4:0] shamtOut;
	reg [5:0] functOut;
	reg [15:0] immediateOut;
	reg [25:0] targetOut;

	assign OpCode = OpCodeOut;
	assign Rs = RsOut;
	assign Rt = RtOut;
	assign Rd = RdOut;
	assign shamt = shamtOut;
	assign funct = functOut;
	assign immediate = immediateOut;
	assign target = targetOut;

	always @(*) begin
		OpCodeOut <= Instruction[31:26];
		/* R-type */
		if (OpCodeOut == 6'b0) begin
			RsOut <= Instruction[25:21];
			RtOut <= Instruction[20:16];
			RdOut <= Instruction[15:11];
			shamtOut <= Instruction[10:6];
			functOut <= Instruction[5:0];
			immediateOut <= 16'b0;
			targetOut <= 26'b0;
		end
		/* J-type (2, 3 and 26) */
		else if (OpCodeOut == 6'b10 || OpCodeOut == 6'b11 || OpCodeOut == 6'b11010 ) begin
			RsOut <= 5'b0;
			RtOut <= 5'b0;
			RdOut <= 5'b0;
			shamtOut <= 5'b0;
			functOut <= 6'b0;
			immediateOut <= 16'b0;
			targetOut <= Instruction[25:0];
		end
		/* I-type */
		else begin
			RsOut <= Instruction[25:21];
			RtOut <= Instruction[20:16];
			RdOut <= 5'b0;
			shamtOut <= 5'b0;
			functOut <= 6'b0;
			immediateOut <= Instruction[15:0];
			targetOut <= 26'b0;
		end
	end
endmodule