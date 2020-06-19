module mipsReg(ReadAddr1,ReadAddr2,WriteAddr,WriteData,ReadData1,ReadData2, RegWrite, Reset);
	/* Inputs and outputs */
	input [4:0] ReadAddr1;
	input [4:0] ReadAddr2;
	input [4:0] WriteAddr;
	input [31:0] WriteData;
	output reg [31:0] ReadData1;
	output reg [31:0] ReadData2;
	input RegWrite;
	input Reset;

	/* Registers */
	reg [31:0] regFile [31:0];
	integer i;

	initial
		begin
		regFile[0] = 32'h0; // $zero
		end

	always @(*) 
        begin
	if (Reset)
	    begin
		for (i = 0; i<32; i= i + 1) 
                begin
                    regFile[i] = 0;
                end
	    end

        if (RegWrite)
            begin
            /* Writing */
            if (WriteAddr)
                begin
                /* Writes in any register
                that is not zero */
                regFile[WriteAddr] <= WriteData;
                end
            end
        else
            begin
            /* Reading */
            assign ReadData1 = regFile[ReadAddr1];
            assign ReadData2 = regFile[ReadAddr2];
            end
        end
endmodule