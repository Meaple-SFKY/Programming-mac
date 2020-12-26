module ALU(
  input wire[15:0] in1, in2,
  input wire alu_op,
  output reg[15:0] Z
);

  always@* begin
    if(alu_op==1)
      Z = in1+in2;
    else
      Z = 1'bX;
  end

endmodule
