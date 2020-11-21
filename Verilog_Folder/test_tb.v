`include "test.v"

module vaddsws_tb;

reg	[31: 0]	vra;
reg	[31: 0]	vrb;
wire	[31: 0]	vrt;
wire	sat;

initial
begin
	$dumpfile("test.vcd");
	$dumpvars(0, vaddsws_tb);
	assign vra=32'hffffffff;
	assign vrb=32'hffffffff;
	#100
	assign vra=32'h01234567;
	assign vrb=32'h76543210;
	#100
	$finish;
end

vaddsws add( .vra(vra), .vrb(vrb), .vrt(vrt), .sat(sat) );

endmodule