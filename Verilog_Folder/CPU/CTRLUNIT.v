module CTRLUNIT (
	input wire [3 : 0] ins,
	output reg stop, pcWR, accWR, memWR,
	output reg [3 : 0] aluCode
);

	initial
	begin
		stop = 0;
		pcWR = 0;
		accWR = 0;
		memWR = 0;
		aluCode = 4'bX;
	end

	always @(ins)
	begin

		if (ins[3] == 0)
		begin
			case (ins[3 : 2])
				2'b00: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100100;		//000	add
				2'b01: {stop, pcWR, accWR, memWR, aluCode} = 8'b00010101;		//001	sta
				2'b10: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100110;		//010	lda
				2'b11: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100000;		//011	cla
			endcase
		end
		else
		begin
			if (ins[2] == 0)
			begin
				if (ins[1] == 0)
				begin
					{stop, pcWR, accWR, memWR, aluCode} = 8'b00100001;			//100	com
				end
				else
				begin
					{stop, pcWR, accWR, memWR, aluCode} = 8'b01001111;			//101	jmp
				end
			end
			else
			begin
				case (ins[1 : 0])
					2'b00: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100111;	//1100	ban
					2'b01: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100010;	//1101	shr
					2'b10: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100011;	//1110	csl
					2'b11: {stop, pcWR, accWR, memWR, aluCode} = 8'b10001111;	//1111	stp
				endcase
			end
		end
	end

endmodule