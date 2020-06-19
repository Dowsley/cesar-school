module mipsReg_tb;
	reg [4:0] ReadAddr1;
	reg [4:0] ReadAddr2;
	reg [4:0] WriteAddr;
	reg [31:0] WriteData;

	wire [31:0] ReadData1;
	wire [31:0] ReadData2;

	reg RegWrite;
	reg Reset;

	integer i;

	initial
        begin
	    Reset = 0;
	    /* Writing values */
	    RegWrite <= 1;
            for (i = 0; i<32; i= i + 1) 
                begin
                    WriteAddr <= i;
                    WriteData <= i+1;
		    #1;
                end

	    /* Reading values in pairs */
            RegWrite <= 0;
            for (i = 0; i<31; i= i + 2) 
                begin
                    ReadAddr1 <= i;
	 	    ReadAddr2 <= i+1;
		    #1;
                end
	    
	    Reset = 1;

	    /* Read reseted values */
            for (i = 0; i<31; i= i + 2) 
                begin
                    ReadAddr1 <= i;
	 	    ReadAddr2 <= i+1;
		    #1;
                end
		
		
        end

	mipsReg op (ReadAddr1,ReadAddr2,WriteAddr,WriteData,ReadData1,ReadData2, RegWrite, Reset);
endmodule 
