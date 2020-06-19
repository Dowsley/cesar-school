module ula_tb;

	reg [31:0] inA, inB;
	reg [5:0] ALUCode;
	reg [4:0] shamt;
	wire [31:0] out;

	reg [5:0] codes [6:0];
	integer i;
 
	initial
    begin
        inA = 32'ha ;
        inB = 32'h5;
        shamt = 5'h05;
        ALUCode = 6'h20;
        i = 0;
        codes[0] = 6'h20;
        codes[1] = 6'h22;
        codes[2] = 6'h24;
        codes[3] = 6'h25;
        codes[4] = 6'h03;
        codes[5] = 6'h02;
        codes[6] = 6'h00;
    end
	
	always
    begin
        #20 i = i + 1;
        ALUCode = codes[i];
    end

	main op (inA,inB,ALUCode,out,shamt);
endmodule 
