`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.08.2023 15:59:53
// Design Name: 
// Module Name: POS
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


module POS(
    input a,
    input b,
    input c,d,
    output y
    );
    
    assign y=(~d|b)&(c|a|~b)&(a|~b|~c)&(~a|b|~c)&(~a|c|d);
endmodule
