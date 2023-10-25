`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.08.2023 14:31:21
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
    reg I0,I1,S;
    wire Y;
    
    MUX uut(I0,I1,S,Y);
    
    initial begin
   S=0;I0=1;I1=0;
   #10
    I0=0;I1=0;
   #10
    S=1;I0=1;I1=0;
   #10
    I0=0;I1=0;
   #10
   
    $finish();
     end
endmodule
