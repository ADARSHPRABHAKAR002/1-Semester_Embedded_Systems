`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 09:02:53
// Design Name: 
// Module Name: one_bit_adder
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


module one_bit_adder(input a,b,cin,output sum,carry);
wire w1,w2,w3;
half_adderHA1(a,b,w1,w2);
half_adderHA2(w1,cin,sum,w3);
or N(carry,w2,w3);
endmodule
module half_adder(input a,b,output sum,carry);
assign sum =a^b ;
assign carry=a&b ;
endmodule