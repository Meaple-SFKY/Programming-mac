`include "CPU.v"

module CPU_TB;
	reg clk, rst;

	initial
	begin
		$dumpfile("test.vcd");
		$dumpvars(0, CPU_TB);
		clk = 1;
		rst = 0;

		#1
		rst = ~rst;

		#1
		rst = ~rst;

		#18
		$stop;
	end

	always #1
	begin
		clk = ~clk;
	end

	CPU cpu (
		.clk(clk), .rst(rst)
	);

endmodule