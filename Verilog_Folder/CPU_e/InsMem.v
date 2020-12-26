module InsMem(
	input wire[7:0] addr,
	output wire[15:0] inst
);

	reg[15:0] insMem [0:63];

	initial begin
		$readmemh("ins.data",insMem);
	end

	assign inst = insMem[addr];

endmodule