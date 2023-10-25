`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.08.2023 15:33:08
// Design Name: 
// Module Name: SOP
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


module SOP(
    input a,
    input b,
    input c,
    input d,
    output y
    );
    assign y=(~c&a)|(~d&a)|(d&a&~b)|(b&c&~d);
endmodule
