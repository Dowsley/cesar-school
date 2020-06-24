module pc_TB;

	reg [31:0] Input;
	reg LoadEnable;

	wire [31:0] Address;

	initial begin
		Input = 32'h4;
            	LoadEnable = 0;
            	#20
            	LoadEnable = 1;
        end

	PC op (Input, Address, LoadEnable);
endmodule
