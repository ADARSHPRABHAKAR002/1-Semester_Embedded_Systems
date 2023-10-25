`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10.08.2023 15:10:00
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
reg a,b;
wire sum,carry;

half_adder uut(a,b,sum,carry);

initial begin
a = 0; b = 0;
#10
a =0; b = 1;
#10
a = 1; b = 0;
#10
a = 1; b =1;
#10
$finish();
end

endmodule
