`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10.08.2023 16:08:00
// Design Name: 
// Module Name: stimulus_2
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


module stimulus_2
reg a,b,c;
wire sum,carry;

full_adder utt(a,b,c,sum,carry);
a=0;b=0,c=0;
#10
a=0;b=0,c=1;
#10
a=0;b=1,c=0;
#10
a=0;b=1,c=1;
#10
a=1;b=0,c=0;
#10
a=1;b=0,c=1;
#10
a=1;b=1,c=0;
#10
a=1;b=1,c=01;

    );
endmodule
