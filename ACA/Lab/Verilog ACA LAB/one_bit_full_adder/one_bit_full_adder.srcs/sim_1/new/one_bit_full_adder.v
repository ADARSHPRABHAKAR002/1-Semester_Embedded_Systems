`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 08:44:09
// Design Name: 
// Module Name: one_bit_full_adder
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module one_bit_full_adder();
reg a,b,cin;
wire sum,carry;
integer i;
full_adder dut(.a(a),.b(b),.c(cin),.sum(sum),.carry(carry));
initial
begin
a=1'b0;
b=1'b0;
cin=1'b0;
end initial
begin 
for(i=0;i<8;i=i+1)
begin
{a,b,cin}=i;
#10;
end
end
initial
$monitor("input a=%b,b=%b,c=%b,output sum =%b,carry=%b,a,b,cin,sum,carry");
initial
#100$finish;
endmodule
