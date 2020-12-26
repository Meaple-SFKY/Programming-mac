module PC (
  input clk, rst,
  output reg[7:0] pc
);


always@(posedge clk) begin
  if (rst == 1'b1)
    pc = 0;
  else
    pc = pc + 1;
end

endmodule