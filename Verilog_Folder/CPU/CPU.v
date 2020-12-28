`include "PC.v"
`include "INSREG.v"
`include "ACC.v"
`include "MEMOR.v"
`include "CTRLUNIT.v"
`include "ALU.v"

module CPU (
	input wire clk, rst
);

	wire stop, pcWR, accWR, memWR, ifBan;
	wire [3 : 0] aluCode;
	wire [7 : 0] Addr;
	wire [11 : 0] ins;
	wire [15 : 0] inDataA, inDataB, aluData;

	PC pc (
		.clk(clk), .rst(rst), .stop(stop), .pcWR(pcWR), .ifBan(ifBan),
		.jump(ins[7 : 0]), .Addr(Addr)
	);

	INSREG insreg (
		.Addr(Addr), .ins(ins)
	);

	ACC acc (
		.clk(clk), .accWR(accWR),
		.inData(aluData),
		.outData(inDataA)
	);

	MEMOR memor (
		.memWR(memWR), .clk(clk),
		.Addr(ins[7 : 0]),
		.inData(aluData),
		.outData(inDataB)
	);

	CTRLUNIT cu (
		.ins(ins[11 : 8]),
		.stop(stop), .pcWR(pcWR), .accWR(accWR), .memWR(memWR),
		.aluCode(aluCode)
	);

	ALU alu (
		.aluCode(aluCode),
		.inDataA(inDataA), .inDataB(inDataB),
		.ifBan(ifBan),
		.aluData(aluData)
	);

endmodule