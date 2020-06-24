module PC(Input, Address, LoadEnable);

	input [31:0]  Input;
	input LoadEnable;
	output [31:0]  Address;

    	reg [31:0] pc;

	assign Address = pc;

	initial begin
		pc <= 32'h00000000;
	end

	always @(*) begin
		if (LoadEnable == 1) begin
			pc <= Input;
		end
	end
endmodule