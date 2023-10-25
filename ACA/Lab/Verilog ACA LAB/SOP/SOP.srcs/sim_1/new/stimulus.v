`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.08.2023 15:37:27
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
reg a,b,c,d;
wire y;

SOP uut(a,b,c,d,y);

initial begin

a=0;b=0;c=0;d=0;
#10
a=0;b=0;c=0;d=1;
#10
a=0;b=0;c=1;d=0;
#10
a=0;b=0;c=1;d=1;
#10
a=0;b=1;c=0;d=0;
#10
a=0;b=1;c=0;d=1;
#10
a=0;b=1;c=1;d=0;
#10
a=0;b=1;c=1;d=1;
#10
a=1;b=0;c=0;d=0;
#10
a=1;b=0;c=0;d=1;
#10
a=1;b=0;c=1;d=0;
#10
a=1;b=0;c=1;d=1;
#10
a=1;b=1;c=0;d=0;
#10
a=1;b=1;c=0;d=1;
#10
a=1;b=1;c=1;d=0;
#10
a=1;b=1;c=1;d=1;
#10

$finish();
end
endmodule
