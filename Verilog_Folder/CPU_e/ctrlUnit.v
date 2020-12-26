module ctrlUnit(
  input wire[6:0] opCode,
  output reg WE, alu_op
);

  always @* begin
    if(opCode == 7'b0000001)
      begin
        WE = 1;
        alu_op = 1;
      end
    else
      begin
        WE = 0;
        alu_op = 0;
      end
  end
endmodule 
