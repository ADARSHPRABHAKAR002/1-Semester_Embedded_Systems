`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 31.08.2023 15:15:52
// Design Name: 
// Module Name: stimulus
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
module stimulus;
reg A,B;
wire D0,D1,D2,D3;

decoder uut(A,B,D0,D1,D2,D3);

initial begin

A=0; B=0;
#10
A=0; B=1;
#10
A=1; B=0;
#10
A=1; B=1;
#10

$finish();
end
endmodule
