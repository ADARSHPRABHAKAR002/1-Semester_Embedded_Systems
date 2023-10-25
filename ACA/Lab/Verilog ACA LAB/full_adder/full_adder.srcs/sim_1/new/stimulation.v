`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 09:43:07
// Design Name: 
// Module Name: stimulation
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


module stimulation();
reg a,b,cin;
wire sum,carry;
integer i;
full_adder uut(a,b,cin,sum,carry);
initial begin
a=1'b0;
b=1'b0;
cin=1'b0;
end
initial begin
for(i=0;i<8;i=i+1)
begin 
{a,b,cin}=i;
#10;
end
end
initial
$monitor("input a=%b,b=%b,c=%b,output sum=%b,carry=%b",a,b,cin,sum,carry);
initial#100$finish;
endmodule
