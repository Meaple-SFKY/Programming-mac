`include "CPU.v"
module CPU_tb;
	reg clk, rst;

	always#5 clk = ~clk;

	initial begin
		$dumpfile("mytest.vcd");
		$dumpvars(0, CPU_tb);
		clk = 0;
		rst = 1;

		#10
		rst = 0;
		#30

		$stop;
	end

	CPU cpu(.clk(clk), .rst(rst));
endmodule
