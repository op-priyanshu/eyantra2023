`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/01/12 13:16:55
// Design Name: 
// Module Name: InstrMem
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


module InstrMem(
    input   [19:0]  addr,
    output  [31:0]  dout
    );
    
    reg [7:0]  mem [0:100];
    /*initialize memory*/
    integer i;
    initial begin
 
        {mem[3],  mem[2],  mem[1],  mem[0]}     <= 32'b0000000_01010_00000_000_00100_0010011;   //      ADDI x4, x0, 10
                                                                                                //sort : 
        {mem[7],  mem[6],  mem[5],  mem[4]}     <= 32'b0000001_00000_00100_000_11100_1100011;   //      BEQ x4, x0, Load
        {mem[11], mem[10], mem[9],  mem[8]}     <= 32'b1111111_11111_00100_000_00100_0010011;   //      ADDI x4, x4, -1
        {mem[15], mem[14], mem[13], mem[12]}    <= 32'b0000001_00100_00000_000_00101_0010011;   //      ADDI x5, x0, 36
        {mem[19], mem[18], mem[17], mem[16]}    <= 32'b1111111_11100_00101_000_00110_0010011;   //      ADDI x6, x5, -4
                                                                                                //Itr : 
        {mem[23], mem[22], mem[21], mem[20]}    <= 32'b1111111_00000_00101_000_10001_1100011;   //      BEQ x5, x0, Sort 
        {mem[27], mem[26], mem[25], mem[24]}    <= 32'b0000000_00000_00101_010_00111_0000011;   //      LW x7, 0(x5)        
        {mem[31], mem[30], mem[29], mem[28]}    <= 32'b0000000_00000_00110_010_01000_0000011;   //      LW x8, 0(x6)        
        {mem[35], mem[34], mem[33], mem[32]}    <= 32'b0000000_00111_01000_010_01001_0110011;   //      SLT x9, x8, x7      
        {mem[39], mem[38], mem[37], mem[36]}    <= 32'b0000000_00000_01001_001_01100_1100011;   //      BNE x9, x0, Not Swap
                                                                                                //Swap :                    
        {mem[43], mem[42], mem[41], mem[40]}    <= 32'b0000000_01000_00101_010_00000_0100011;   //      SW x8, 0(x5)        
        {mem[47], mem[46], mem[45], mem[44]}    <= 32'b0000000_00111_00110_010_00000_0100011;   //      SW x7, 0(x6)        
                                                                                                //Not Swap:                    
        {mem[51], mem[50], mem[49], mem[48]}    <= 32'b1111111_11100_00101_000_00101_0010011;   //      ADDI x5, x5, -4     
        {mem[55], mem[54], mem[53], mem[52]}    <= 32'b1111111_11100_00101_000_00110_0010011;   //      ADDI x6, x5, -4     
        {mem[59], mem[58], mem[57], mem[56]}    <= 32'b1111110_11101_11111_111_01010_1101111;   //      JAL x10, Itr      
                                                                                                //Load:
        {mem[63], mem[62], mem[61], mem[60]}    <= 32'b0000000_00000_00000_010_00001_0000011;   //      LW x1, 0(x0)
        {mem[67], mem[66], mem[65], mem[64]}    <= 32'b0000000_00100_00000_010_00010_0000011;   //      LW x2, 4(x0)
        {mem[71], mem[70], mem[69], mem[68]}    <= 32'b0000000_01000_00000_010_00011_0000011;   //      LW x3, 8(x0)
        {mem[75], mem[74], mem[73], mem[72]}    <= 32'b0000000_01100_00000_010_00100_0000011;   //      LW x4, 12(x0)
        {mem[79], mem[78], mem[77], mem[76]}    <= 32'b0000000_10000_00000_010_00101_0000011;   //      LW x5, 16(x0)
        {mem[83], mem[82], mem[81], mem[80]}    <= 32'b0000000_10100_00000_010_00110_0000011;   //      LW x6, 20(x0)
        {mem[87], mem[86], mem[85], mem[84]}    <= 32'b0000000_11000_00000_010_00111_0000011;   //      LW x7, 24(x0)
        {mem[91], mem[90], mem[89], mem[88]}    <= 32'b0000000_11100_00000_010_01000_0000011;   //      LW x8, 28(x0)
        {mem[95], mem[94], mem[93], mem[92]}    <= 32'b0000001_00000_00000_010_01001_0000011;   //      LW x9, 32(x0)
        {mem[99], mem[98], mem[97], mem[96]}    <= 32'b0000001_00100_00000_010_01010_0000011;   //      LW x10, 36(x0)
        
        for (i = 100; i < 100; i = i + 1) begin
            mem[i] <= 20'h0_0000;
        end
    end
    
    assign dout = {mem[addr + 3], mem[addr + 2], mem[addr + 1], mem[addr]};

endmodule
