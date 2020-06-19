module main(inA, inB, ALUCode, out, shamt);
	input [31:0] inA;
	input [31:0] inB;
	input [5:0] ALUCode;
	input [4:0] shamt; // Possível valor: Entre 5 e 30
	output [31:0] out;
	reg [31:0] result;
	
	assign out = result;

	always @(*) 
	begin
        case (ALUCode)
            6'h20 : result <= (inA + inB);     // 32 = Sum
            6'h22 : result <= (inA - inB);     // 34 = Subtraction
            6'h24 : result <= (inA & inB);     // 36 = AND
            6'h25 : result <= (inA | inB);     // 37 = OR
            6'h03 : result <= (inA >>> shamt); // 3 = Shift Right Arithm (Divide ->)
            6'h02 : result <= (inA >> shamt);  // 2 = Shift Right Logical
            6'h00 : result <= (inA << shamt);  // 0 = Shift Left Logical
            default : result <= 0;
        endcase
	end
endmodule