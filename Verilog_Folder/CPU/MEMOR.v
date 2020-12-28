module MEMOR (
	input memWR, clk,
	input wire [7 : 0] Addr,
	input wire [15 : 0] inData,
	output wire [15 : 0] outData
);

	reg [15 : 0] unit [8'b11111111 : 0];

	assign outData = unit[Addr];

	initial
	begin
		unit[0] = 16'h0002;
		unit[1] = 16'h8000;
		unit[2] = 16'h0001;
	end

	always @(negedge clk)
	begin
		if (memWR == 1)
			unit[Addr] = inData;
	end
endmodule