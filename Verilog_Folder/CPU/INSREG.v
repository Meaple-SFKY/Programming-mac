module INSREG (
	input wire [7 : 0] Addr,
	output reg [11 : 0] ins
);

	reg [11 : 0] unit[8'b11111111:0];

	initial
	begin
		unit[0] = 12'b010000000001;		//lda
		unit[1] = 12'b000000000010;		//add
		unit[2] = 12'b110100000000;		//shr
		unit[3] = 12'b000000000010;		//add
		unit[4] = 12'b000000000010;		//add
		unit[5] = 12'b000000000001;		//add
		unit[6] = 12'b001000000010;		//sta
		unit[7] = 12'b101000000001;		//jmp
		unit[8] = 12'b110000000010;		//ban
		unit[9] = 12'b111100000000;		//stp
	end

	always @*
	begin
		ins = unit[Addr];
	end

endmodule