`include "InsMem.v"
`include "pc.v"
`include "ctrlUnit.v"
`include "regFile.v"
`include "ALU.v"

module CPU(
	input clk, rst
);

	wire[7:0] pc_addr;
	wire[15:0] inst;
	wire WE, alu_op;
	wire[15:0] outA, outB,result;
	
	PC pc(.clk(clk), .rst(rst), .pc(pc_addr));
	InsMem insMem(.addr(pc_addr),.inst(inst));
	ctrlUnit ctl(.opCode(inst[15:9]),.WE(WE), .alu_op(alu_op));
	regFile regs(.addrA(inst[8:6]), .addrB(inst[5:3]), .inAddr(inst[2:0]),
				.outA(outA), .outB(outB), .inData(result), .WE(WE), .clk(clk)
	);
	ALU alu(.in1(outA), .in2(outB),.alu_op(alu_op), .Z(result) );

endmodule
