`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 31.08.2023 14:36:46
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
reg D0,D1,D2,D3;
wire A,B;

encoder uut(D1,D2,D0,D3,A,B);

initial begin

D3=0; D2=0; D1=0; D0=1;
#10
D3=0; D2=0; D1=1; D0=0;
#10
D3=0; D2=1; D1=0; D0=0;
#10
D3=1; D2=0; D1=0; D0=0;
#10

$finish();
end
endmodule
